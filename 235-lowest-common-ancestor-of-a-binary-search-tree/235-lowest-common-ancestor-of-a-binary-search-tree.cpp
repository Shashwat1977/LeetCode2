/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        return helper(root,p,q);
    }
    TreeNode* helper(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root == NULL) return NULL;
        if((root->val >= p->val && root->val<=q->val) || (root->val<=p->val && root->val >= q->val)) return root;
        if(p->val > root->val && q->val>root->val){
            return helper(root->right,p,q);
        }else{
            return helper(root->left,p,q);
        }
    }
};