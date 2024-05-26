/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int l=0;
        ListNode * temp=head;
        if(head->next==NULL)
        {
            return NULL;
        }
        while(temp!=NULL)
        {
            l=l+1;
            temp=temp->next;
        }
        l=l/2;
        int count=0;
        temp=head;
        ListNode * prev=NULL;
        while(temp!=NULL)
        {
            if(count==l)
            {
                prev->next=temp->next;
                return head;
            }
            prev=temp;
            temp=temp->next;
            count=count+1;
        }
        return head;
    }
};