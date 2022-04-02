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
    TreeNode* invertTree(TreeNode* root) {
        return newTree(root);
    }
    TreeNode* newTree(TreeNode* root){
        if(root == NULL) return NULL;
        TreeNode* node =  new TreeNode(root->val);
        node->left = newTree(root->right);
        node->right = newTree(root->left);
        return node;
    }
};