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
    ListNode * reverse(ListNode * head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode * newhead=reverse(head->next);
        ListNode * front=head->next;
        front->next=head;
        head->next=NULL;
        return newhead;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode * slow,* fast;
        slow=head;
        fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode * first=head;
        ListNode * second=reverse(slow->next);
        while(second!=NULL)
        {
            if(first->val!=second->val)
            {
                reverse(slow->next);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverse(slow->next);
        return true;
    }
};