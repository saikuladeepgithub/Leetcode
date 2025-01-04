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
    void deleteNode(ListNode* node) {
        

        ListNode * prev = NULL;
        while(node->next!=NULL)
        {
            ListNode * nextnode = node->next;
            node->val = nextnode->val;
            prev = node;
            node = nextnode;
        }

        prev->next = NULL;

    }
};