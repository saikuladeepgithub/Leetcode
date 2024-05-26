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
    ListNode* middleNode(ListNode* head) {
            ListNode * temp=head;
    int l=0;
    while(temp!=NULL)
    {
        l=l+1;
        temp=temp->next;
    }
     l=(l/2)+1;
    int count=0;
    temp=head;
    while(temp!=NULL)
    {
        count=count+1;
        if(count==l)
        {
            break;
        }
        temp=temp->next;
    }
    return temp;
    }
};