/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        Node* dummy = root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int k = q.size();
            Node* temp = q.front();
            for(int i = 0;i<k;i++){
                Node* it = q.front();q.pop();
                if(i!=0){
                    temp->next = it;
                    temp = it;
                    if(i == k-1) it->next == NULL;
                }
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
        }
        return dummy;
    }
};