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
    int res = 0;
    int longestUnivaluePath(TreeNode* root) {
     int val = func(root);
        return res;
    }
    int func(TreeNode* root){
        if(root == NULL) return 0;
        int left = 0;int right = 0;
        int ls = func(root->left);
        int rs = func(root->right);
        if(root->left != NULL && root->val == root->left->val){
            left = ls+1;
        }
        if(root->right != NULL && root->right->val == root->val){
            right = rs+1;
        }
        res = max(res,left+right);
        return max(left,right);
    }
};