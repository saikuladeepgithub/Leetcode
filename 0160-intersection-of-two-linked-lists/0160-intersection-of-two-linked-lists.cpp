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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // unordered_map<ListNode *,int> mpp;
        // ListNode * temp=headA;
        // while(temp!=NULL)
        // {
        //     mpp[temp]=1;
        //     temp=temp->next;
        // }
        // temp=headB;
        // while(temp!=NULL)
        // {
        //     if(mpp.find(temp)!=mpp.end()) return temp;
        //     temp=temp->next;
        // }
        // return NULL; 
        
        // optimal solution 
        if(headA==NULL || headB==NULL) return NULL;
        ListNode * temp1,*temp2;
        temp1=headA;
        temp2=headB;
        while(temp1!=temp2)
        {
            temp1=temp1->next;
            temp2=temp2->next;
            if(temp1==temp2) return temp1;
            if(temp1==NULL) temp1=headB;
            if(temp2==NULL) temp2=headA;
        }
        return temp1;
    }
};