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
    int ans;
    int goodNodes(TreeNode* root) {
        helper(root,root->val);
        return ans;
    }
    void helper(TreeNode* root,int val){
        if(root == NULL) return;
        if(root->val >= val){
            val = root->val;
            ans++;
        }
        helper(root->left,val);
        helper(root->right,val);
        
        }
};