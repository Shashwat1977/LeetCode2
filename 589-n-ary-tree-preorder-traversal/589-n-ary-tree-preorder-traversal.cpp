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
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        pre(root,ans);
        return ans;
    }
    void pre(Node* root,vector<int> & ans){
        if(root == NULL) return;
        ans.push_back(root->val);
        int i;
        for(i = 0;i<root->children.size();i++){
            pre(root->children[i],ans);
        }
    }
};