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
    vector<int> rightSideView(TreeNode* root) {
                        queue<pair<TreeNode *,int>> q;
        
        map<int,int> mpp;
        
        if(root==NULL) return {};
        
        q.push({root,0});
        
        while(!q.empty())
        {
            auto p = q.front();
            TreeNode * node = q.front().first;
            q.pop();
            if(node->left) q.push({node->left,p.second+1});
            if(node->right) q.push({node->right,p.second+1});
            
            mpp[p.second] = node->val;
            
        }
        vector<int> res;
        for(auto it : mpp)
        {
            res.push_back(it.second);
        }
        
        return res;
    }
};