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
    int sum;
    int sumRootToLeaf(TreeNode* root) {
        sum = 0;
        int val = 0;
        helper(root,val);
        return sum;
    }
    void helper(TreeNode* root,int val){
        if(root == NULL) return;
        val = 2*val+root->val;
        if(root->left == NULL && root->right == NULL) sum += val;
        helper(root->left,val);
        helper(root->right,val);
    }
};