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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first=-1;
        int prev=-1;
        int currentindex=1;
        ListNode * prevnode,*currentnode,*nextnode;
        int mindifference=INT_MAX;
        prevnode=head;
        currentnode=head->next;
        nextnode=currentnode->next;
        while(currentnode->next!=NULL)
        {
            if((currentnode->val>nextnode->val && currentnode->val>prevnode->val) ||
              (currentnode->val<nextnode->val && currentnode->val<prevnode->val))
            {
                if(first==-1)
                {
                    first=currentindex;
                    prev=currentindex;
                }
                else
                {
                    mindifference=min(mindifference,currentindex-prev);
                    prev=currentindex;
                }
                
            }
            prevnode=currentnode;
            currentnode=currentnode->next;
            nextnode=currentnode->next;
            currentindex++;
        }
        if(mindifference==INT_MAX || first==prev)
        {
            return {-1,-1};
        }
        return {mindifference,prev-first};
    }
};