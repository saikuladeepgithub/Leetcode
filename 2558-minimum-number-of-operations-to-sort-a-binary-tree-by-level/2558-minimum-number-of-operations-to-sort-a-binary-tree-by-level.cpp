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
    int minswaps(vector<int> & original)
    {
        int n = original.size();
        vector<int> target = original;
        sort(target.begin(),target.end());
        int swaps = 0;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++)
        {
            mpp[original[i]] = i;
        }

        for(int i=0;i<n;i++)
        {
            if(original[i]!=target[i]) swaps++;

            int targetpos = mpp[target[i]];
            mpp[original[i]] = targetpos;
            mpp[target[i]] = i;
            swap(original[i],original[targetpos]);
        }

        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        
        queue < TreeNode *> que;

        que.push(root);
        int swaps = 0;
        while(!que.empty())
        {
            int levelsize = que.size();

            vector<int> original (levelsize);

            for(int i=0;i<levelsize;i++)
            {
                TreeNode * node = que.front();
                que.pop();

                original[i] = node->val;
                if(node->left!=NULL) que.push(node->left);
                if(node->right!=NULL) que.push(node->right);
            }

            swaps += minswaps(original);
        }

        return swaps;
    }
};