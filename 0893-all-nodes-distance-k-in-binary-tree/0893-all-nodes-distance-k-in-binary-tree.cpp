/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode *, TreeNode *> func(TreeNode * root)
    {
        unordered_map<TreeNode *, TreeNode *>  mpp;
        if(root == NULL) return mpp;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode * node = q.front();
                q.pop();
                if(node->left)
                {
                    q.push(node->left);
                    mpp[node->left] = node;
                }
                if(node->right)
                {
                    q.push(node->right);
                    mpp[node->right] = node;
                }
            }
        }

        return mpp;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *, TreeNode *> mpp;
        mpp = func(root);

        queue<TreeNode *> q;
        q.push(target);
        int curlevel = 0;
        unordered_map<TreeNode *, bool> vis; 
        vis[target] = true;
        while(!q.empty())
        {
            int size = q.size();
            if(curlevel++ == k) break;

            for(int i=0;i<size;i++)
            {
                TreeNode * cur = q.front();
                q.pop();
                if(cur->left && !vis[cur->left])
                {
                    q.push(cur->left);
                    vis[cur->left] = true;
                }
                if(cur->right && !vis[cur->right])
                {
                    q.push(cur->right);
                    vis[cur->right] = true;

                }
                if(mpp[cur] && !vis[mpp[cur]])
                {
                    q.push(mpp[cur]);
                    vis[mpp[cur]] = true;
                }
            }
        }

            vector<int> res;
            int l = q.size();
            for(int i=0;i<l;i++)
            {
                res.push_back(q.front()->val);
                q.pop();
            }
            return res;
    }
};