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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        priority_queue<int,vector<int>,greater<int>> pq;
        inorder(root1,pq);
        inorder(root2,pq);
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
    void inorder(TreeNode* root,priority_queue<int,vector<int>,greater<int>>& pq){
        if(root == NULL) return;
        inorder(root->left,pq);
        pq.push(root->val);
        inorder(root->right,pq);
    }
};