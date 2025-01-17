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
class BSTIterator{
public:
    stack<TreeNode *> st;
    bool reverse;
    BSTIterator(TreeNode * root,bool isreverse)
    {
        reverse = isreverse;
        helper(root);
    }
    int next()
    {
        TreeNode * topnode = st.top();
        st.pop();
        if(reverse)
        {
            helper(topnode->left);
        } 
        else
            helper(topnode->right);
        return topnode->val;
    }
    void helper(TreeNode * root)
    {
        if(reverse)
        {
            while(root)
            {
                st.push(root);
                root = root->right;
            }
        }
        else
        {
            while(root)
            {
                st.push(root);
                root = root->left;
            }
        }
    }
};
class Solution {
public:
    set<int> st;
    vector<int> inorder;
    void helper(TreeNode * root)
    {
        if(root == NULL)
            return;
        helper(root->left);
        st.insert(root->val);
        inorder.push_back(root->val);
        helper(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        
        // helper(root);
        // int n = inorder.size();
        // for(int i=0;i<n;i++)
        // {
        //     int comp = k - inorder[i];
        //     if(st.find(comp)!=st.end() && (comp+comp)!=k)
        //         return true;
        // }
        // return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i = l.next();
        int j = r.next();

        while(i<j)
        {
            if(i+j == k)
                return true;
            else if((i+j)<k)
                i = l.next();
            else
                j = r.next();
        }

        return false;
    }
};