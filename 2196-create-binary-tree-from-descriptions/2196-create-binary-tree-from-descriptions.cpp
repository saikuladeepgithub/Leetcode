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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        set <int> children;
        unordered_map <int,TreeNode *> nodes;
        for(auto node : descriptions)
        {
            int parentval=node[0];
            int childval=node[1];
            int isleft=node[2];
            children.insert(childval);
            if(nodes.find(parentval)==nodes.end())
            {
                nodes[parentval]=new TreeNode(parentval);
            }
            TreeNode * parent=nodes[parentval];
            if(nodes.find(childval)==nodes.end())
            {
                nodes[childval]=new TreeNode(childval);
            }
            TreeNode * child=nodes[childval];
            
            if(isleft)
            {
                parent->left=child;
            }
            else
            {
                parent->right=child;
            }
            
        }
        for(auto node : descriptions)
        {
            int parent=node[0];
            if(children.find(parent)==children.end())
            {
                return nodes[parent];
            }
        }
        return NULL;
    }
};