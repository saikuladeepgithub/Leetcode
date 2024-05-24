/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode* temp=node;
    struct ListNode *prev;
    while(temp->next!=NULL)
    {
        temp->val=temp->next->val;
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    
}