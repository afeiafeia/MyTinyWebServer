#include "CodeC.h"
#include <endian.h>
#include <google/protobuf/descriptor.h>
#include "../../base/Log.h"

namespace afa
{
    static Logger::Ptr logger = LOG_ROOT();
    ProtobufCodeC::ProtobufCodeC()
    :m_error_cb(DefaultErrorCallBack)
    {

    }

    ProtobufCodeC::~ProtobufCodeC()
    {

    }

    void ProtobufCodeC::DefaultErrorCallBack(SP_TcpConnection &sp_conn)
    {
        
    }
    void ProtobufCodeC::Send(SP_TcpConnection &sp_conn,const google::protobuf::Message &msg)
    {
        Buffer buff;
        std::string type_name = msg.GetTypeName();
        int32_t name_len = type_name.size();
        buff.AppendInt32(name_len);
        buff.Append(type_name);
        std::string content = msg.SerializeAsString();
        buff.Append(content);
        
        int32_t len = name_len+static_cast<int32_t>(type_name.size())+static_cast<int32_t>(content.size());
        buff.PrependInt32(len);

        sp_conn->Send(buff);
    }

    void ProtobufCodeC::OnMessage(SP_TcpConnection &sp_conn,Buffer &buff)
    {
        while(buff.ReadableBytes()>=s_min_msg_len+s_header_len)
        {
            //使用循环的目的：如果缓冲区中有多条消息，可以一直处理直到处理完或者剩下的是不完整消息
            int32_t len = buff.GetHeader32();
            if(len>s_max_msg_len||len<s_min_msg_len)
            {
                m_error_cb(sp_conn);
                break;
            }
            else if(buff.ReadableBytes()>=static_cast<size_t>(len+s_header_len))
            {
                //至少有一个完整消息
                LOG_DEBUG(logger)<<"Data's length: "<<len;
                LOG_DEBUG(logger)<<std::string(buff.Peek()+s_header_len,len);
                SP_Message sp_msg = Parse(buff.Peek()+s_header_len,len);
                if(sp_msg)
                {
                    m_message_cb(sp_conn,sp_msg);
                    buff.Retrieve(len);
                }
                else
                {
                    m_error_cb(sp_conn);
                    break;
                }
            }
            else
            {
                //是一个不完整消息
                break;
            }
        }
    }

    SP_Message ProtobufCodeC::Parse(const char* buf,size_t len)
    {
        SP_Message sp_message;
        //获取名字长度
        int32_t name_len;
        memcpy(&name_len,buf,sizeof(int32_t));
        name_len = be32toh(name_len);

        //获取名字
        std::string name(buf+s_header_len,buf+s_header_len+name_len-1);
        google::protobuf::Message* cur_msg = CreateMessage(name);
        if(cur_msg)
        {
            sp_message.reset(cur_msg);
        }
        return sp_message;
    }

    google::protobuf::Message* CreateMessage(std::string type_name)
    {
        google::protobuf::Message* cur_msg = nullptr;
        const google::protobuf::Descriptor* descriptor = google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName(type_name);

        if(descriptor)
        {
            const google::protobuf::Message* prototype = 
            google::protobuf::MessageFactory::generated_factory()->GetPrototype(descriptor);
            if(prototype)
            {
                cur_msg = prototype->New();
            }
        }
        return cur_msg;
    }
}