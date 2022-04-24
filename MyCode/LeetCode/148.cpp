

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* sortList(ListNode* head) {

        ListNode* Newhead= head;
        int length = 0;        
        while(Newhead!=nullptr)
        {
            Newhead = Newhead->next;
            length++;
        }
        Newhead = head;
        ListNode* newTail = head;
        for(int i=1;i<=length;i = i<<1)
        {
            //ListNode* curHead = head;
            ListNode* cur = Newhead;
            bool  first = false;
            while(cur!=nullptr)
            {
                ListNode* nextHead = nullptr;
                ListNode* head1 = cur;
                for(int j=1;j<i&&cur->next!=nullptr;j++)
                {
                    cur = cur->next;
                }
                ListNode* head2 = cur->next;
                cur->next=nullptr;
                cur=head2;
                for(int j=1;j<i&&cur!=nullptr&&cur->next!=nullptr;j++)
                {
                    cur = cur->next;
                }
                if(cur!=nullptr)
                {
                    nextHead = cur->next;
                    cur->next = nullptr;
                }
                ListNode* mergeNode = MergeList(head1,head2);
                if(!first)
                {
                    Newhead = mergeNode;
                    first = true;
                }

                newTail->next= mergeNode;
                while(mergeNode->next!=nullptr)
                {
                    mergeNode = mergeNode->next;
                }
                newTail = mergeNode;
                mergeNode->next = nextHead;
                cur =  nextHead;


            }
        }

        return Newhead;
    }

    ListNode* sortList(ListNode* head,ListNode* tail)
    {
        if(head==nullptr)
        {
            return head;
        }
        if(head->next==tail)
        {
            head->next = nullptr;
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=tail)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast!=tail)
            {
                fast = fast->next;
            }
        }
        ListNode* mid = slow;
        return MergeList(sortList(head,mid),sortList(mid,tail));
    }



    ListNode* MergeList(ListNode* list_L,ListNode* list_R)
    {
        ListNode* head_L = list_L;
        ListNode* head_R = list_R;
        ListNode* tmp = new ListNode();
        ListNode* newHead = tmp;
        while(head_L!=nullptr&&head_R!=nullptr)
        {
            if(head_L->val<=head_R->val)
            {
                tmp->next = head_L;
                head_L = head_L->next;
            }
            else if(head_L->val>head_R->val)
            {
                tmp->next = head_R;
                head_R = head_R->next;
            }
            tmp = tmp->next;
        }
        if(head_L)
        {
            tmp->next = head_L;
        }
        else
        {
            tmp->next = head_R;
        }
        return newHead->next;

    }





};

int main()
{
    Solution so;
    ListNode* node1= new ListNode(1);
    ListNode* node2 = new ListNode(2,node1);
    ListNode* node3 = new ListNode(3,node2);
    ListNode* node4 = new ListNode(4,node3);


    so.sortList(node4);

    return 0;
}