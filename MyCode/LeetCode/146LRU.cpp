
#include <unordered_map>
#include <bits/stl_pair.h>
using namespace std;
class LRUCache {
    struct listNode
    {
        listNode* prev;
        listNode* next;
        pair<int,int> val;
        listNode(listNode* ipPrev,listNode* ipNext,pair<int,int> &iVal)
        :prev(ipPrev)
        ,next(ipNext)
        ,val(iVal)
        {

        }
        listNode()
        :prev(nullptr)
        ,next(nullptr)
        {
            val = pair<int,int>(0,0);
        }
        listNode(listNode* ipPrev)
        :prev(ipPrev)
        ,next(nullptr)
        {
            val = pair<int,int>(0,0);
        }
    };
    private:
    listNode* m_head;
    listNode* m_tail;
    int cap_;
    int size_;

    unordered_map<int,listNode*> hash;
public:
    LRUCache(int capacity) {
        m_head = new listNode();
        listNode* curNode = m_head;
        for(int i=1;i<capacity;i++) 
        {
            listNode* pTmpNode = new listNode(curNode);
            curNode->next = pTmpNode;
            pTmpNode->prev = curNode;
            curNode = pTmpNode;
        }
        m_tail = new listNode();
        m_tail->next = m_head;
        cap_ = capacity;
        size_=0;
    }
    
    int get(int key) {
        if(hash.find(key)!=hash.end())
        {
            if(hash[key]==m_tail)
            {
                return hash[key]->val.second;
            }
            listNode* pre = hash[key]->prev;
            listNode* next = hash[key]->next;
            if(m_head==hash[key]&&next)
            {
                m_head = next;
            }
            if(pre)
            {
                pre->next = next;
            }
            if(next)
            {
                next->prev = pre;
            }
            if(m_tail->next)
            {
                m_tail->next->prev = hash[key];
            }
            hash[key]->next = m_tail->next;

            hash[key]->prev = m_tail;
            m_tail->next = hash[key];
            m_tail = hash[key];

            return m_tail->val.second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(hash.find(key)!=hash.end())
        {
            hash[key]->val.second = value;
            listNode* pre = hash[key]->prev;
            listNode* next = hash[key]->next;
            if(hash[key]!=m_head)
            {
                pre->next = next;
            }
            if(hash[key]!=m_tail)
            {
                next->prev = pre;
            }
     
            if(m_tail->next)
            {
                m_tail->next->prev = hash[key];
            }
            hash[key]->next = m_tail->next;
            m_tail->next = hash[key];
            hash[key]->prev = m_tail;
            
            m_tail = hash[key];
        }
        else
        {
            if(size_<cap_)
            {
                m_tail->next->val = {key,value};
                m_tail = m_tail->next;             
                hash.insert({key,m_tail});
                size_++;
            }
            else
            {
                hash.erase(m_head->val.first);
                m_head->val = {key,value};
                hash.insert({key,m_head});
                listNode* newHead = m_head->next;
                if(cap_>1)
                {
                    newHead->prev = nullptr;
                    m_head->prev = m_tail;
                    m_head->prev->next =m_tail;
                    m_head->next = nullptr;
                    m_tail = m_head;
                    m_head = newHead;
                }

            }

           
        }
    }
};


int main()
{
    LRUCache lru(2);



    lru.put(2,1);
    lru.put(2,2);
    
    int value = lru.get(2);
    lru.put(1,1);

    lru.put(4,1);
    value = lru.get(2);
    return 0;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */