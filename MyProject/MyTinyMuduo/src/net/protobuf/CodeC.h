#ifndef CODEC_H
#define CODEC_H

#include "../TcpConnection.h"
#include "../Buffer.h"

#include <memory>
#include <functional>
#include <google/protobuf/message.h>
#include <string>
namespace afa
{
    //数据格式
    /*
        int32_t len           //存在Buffer的前八个字节
        int32_t name_len      //对应Buffer的m_read_index
        char name[name_len]
        char data[len-name_len-sizeof int32_t]

    */
    typedef std::shared_ptr<google::protobuf::Message> SP_Message;
    class ProtobufCodeC
    {
    public:
        typedef std::function<void(SP_TcpConnection &, SP_Message)> MessageCallBack;
        typedef std::function<void(SP_TcpConnection &)> ErrorCallBack;
        ProtobufCodeC();

        ~ProtobufCodeC();

        static void DefaultErrorCallBack(SP_TcpConnection &sp_conn);

        void SetMessageCallBack(MessageCallBack &cb)
        {
            m_message_cb = cb;
        }

        void SetErrorCallBack(ErrorCallBack &cb)
        {
            m_error_cb = cb;
        }

        /**
         * @brief  把msg中的数据填入sp_conn的发送缓冲区中
         * @param  sp_conn          
         * @param  msg              
         * @author afei
         * @date   2022-04-22
         */
        void Send(SP_TcpConnection &sp_conn,const google::protobuf::Message &msg);

        void OnMessage(SP_TcpConnection &sp_conn,Buffer &buff);
    private:
        SP_Message Parse(const char* buf,size_t len);
        google::protobuf::Message* CreateMessage(std::string tyne_name);

    private:
        MessageCallBack m_message_cb;
        ErrorCallBack   m_error_cb;

        const static int s_header_len = sizeof(int32_t);
        const static int s_min_msg_len = 2*s_header_len;
        const static int s_max_msg_len = 64*1024*1024;//64MB
    };
}


#endif