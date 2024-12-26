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
    // int flag = 0;

    int func(TreeNode * root, int l)
    {
        if(root==NULL) return l;
        int lh = func(root->left,l+1);
        int rh = func(root->right,l+1);
        if(lh==-1 || rh==-1) return -1;
        if(abs(lh-rh)>1) 
        {
            //flag = 1;
            return -1;
        }
        return max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        
        
        return func(root,0)!=-1;
    }
};