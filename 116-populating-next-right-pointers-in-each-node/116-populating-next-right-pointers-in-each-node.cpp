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
        if(root == NULL) return NULL;
        Node* dummy = root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int k = q.size();
            Node* temp = q.front();
            for(int i = 0;i<k;i++){
                auto curr = q.front();q.pop();
                 if(i!= 0){
                    temp->next = curr;
                    temp = curr;
                     if(i == k-1) curr->next = NULL;
                }
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return dummy;
    }
};