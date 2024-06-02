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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL)
        {
            return NULL;
        }
        ListNode * slow,*fast;
        fast=head;
        int i=0;
        while(i<n)
        {
            fast=fast->next;
            i=i+1;
        }
        if(fast==NULL)
        {
            slow=head;
            head=head->next;
            return head;
        }
        slow=head;
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        ListNode * delNode=slow->next;
        slow->next=delNode->next;
        return head;
    }
};