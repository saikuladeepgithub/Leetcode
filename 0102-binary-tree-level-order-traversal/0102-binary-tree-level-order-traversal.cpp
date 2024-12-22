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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        queue<TreeNode * > q;
        if(root==NULL) return {};
        q.push(root);
        while(!q.empty())
        {
            vector<int> level;
            int n = q.size(); // number of elements at each node

            for(int i=0;i<n;i++)
            {
                TreeNode * node = q.front();
                level.push_back(q.front()->val);
                q.pop();
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }

            res.push_back(level);
        }

        return res;

    }
};