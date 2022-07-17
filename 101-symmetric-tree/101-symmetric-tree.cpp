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
    bool isSymmetric(TreeNode* root) {
        return isSym(root->left,root->right);
    }
    bool isSym(TreeNode* left,TreeNode* right){
        if(left == NULL && right == NULL) return true;
        if(left && right == NULL || (left==NULL && right)) return false;
        if(left->val != right->val) return false;
        return isSym(left->left,right->right)&&isSym(left->right,right->left);
    }
};