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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        queue<TreeNode *> q;
        if(!root) return {};
        q.push(root);
        int flag = 0;
        vector<vector<int>> res;
        while(!q.empty())
        {
            vector<int> level;

            int n = q.size();

            for(int i=0;i<n;i++)
            {
                TreeNode * node = q.front();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                level.push_back(node->val);
                q.pop();
            } 
            if(flag) 
                reverse(level.begin(),level.end());
            res.push_back(level);
            if(flag) flag = 0;
            else flag = 1;
        }
        
        return res;
    }
};