/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // ListNode * tail=head;
        // vector<ListNode*> nodePointers;
        // if(head==NULL)
        // {
        //     return NULL;
        // }
        // do
        // {
        //     nodePointers.push_back(tail);
        //     tail=tail->next;
        //     for(int i=0;i<nodePointers.size();i++)
        //     {
        //         if(nodePointers[i]==tail)
        //         {
        //             return tail;
        //         }
        //     }
        // }while(tail!=NULL);
        // return NULL;
        
        
        // map <ListNode *,int> mpp;
        // ListNode * temp=head;
        // while(temp!=NULL)
        // {
        //     if(mpp.find(temp)!=mpp.end())
        //     {
        //         return temp;
        //     }
        //     mpp[temp]==1;
        //     temp=temp->next;
        // }
        // return NULL;
        
        
        ListNode *slow,*fast;
        slow=head;
        fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                slow=head;
                while(slow!=fast)
                {
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};