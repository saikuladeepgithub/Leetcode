/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        int l = findheightleft(root);
        int r = findheightright(root);

        if(l==r) return (1<<l) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int findheightleft(TreeNode * root)
    {
        int l = 0;
        while(root)
        {
            l++;
            root = root->left;
        }
        return l;
    }

    int findheightright(TreeNode * root)
    {
        int l = 0;
        while(root)
        {
            l++;
            root = root->right;
        }

        return l;
    }


};