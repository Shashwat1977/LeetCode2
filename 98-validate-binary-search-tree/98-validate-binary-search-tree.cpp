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
    bool isValidBST(TreeNode* root) {
        return helper(root,-1e10,1e10);
    }
    bool helper(TreeNode* root,long long low,long long high){
        if(root == NULL) return true;
        if(root->val>=high || root->val<=low){
            return false;
        }
        return helper(root->left,low,root->val)&&helper(root->right,root->val,high);
    }
};