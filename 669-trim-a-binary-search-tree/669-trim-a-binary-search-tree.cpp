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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* node = trim(root,low,high);
        TreeNode* dummy = trim(node,low,high);
        return dummy;
    }
    TreeNode* trim(TreeNode* node,int low,int high){
        if(node == NULL) return NULL;
        node->left = trim(node->left,low,high);
        node->right = trim(node->right,low,high);
        if(node->val<low || node->val>high){
            if(node->left) return node->left;
            if(node->right) return node->right;
            return NULL;
        }
        return node;
    }
};