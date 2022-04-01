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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int k = q.size();
            vector<int> temp;
            for(int i = 0;i<k;i++){
                Node* node = q.front();
                q.pop();
                temp.push_back(node->val);
                for(int i = 0;i<node->children.size();i++){
                    if(node->children[i]!= NULL) q.push(node->children[i]);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};