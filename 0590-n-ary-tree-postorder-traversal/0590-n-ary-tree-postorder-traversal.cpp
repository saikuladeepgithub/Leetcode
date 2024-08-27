/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void func(Node * root,vector<int> & res)
    {
        if(root==NULL) return;
        for(auto node : root->children)
        {
            func(node,res);
            res.push_back(node->val);
        }
        
        
    }
    vector<int> postorder(Node* root) {
        if(root==NULL) return {};
        vector<int> res;
        func(root,res);
        res.push_back(root->val);
        return res;
    }
};