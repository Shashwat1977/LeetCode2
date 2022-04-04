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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return tree(root1,root2);
    }
    TreeNode* tree(TreeNode* p,TreeNode* q){
        if(p == NULL && q==NULL) return NULL;
        else if(p==NULL && q!= NULL) return q;
        else if(p!= NULL && q==NULL) return p;
        TreeNode* node = new TreeNode(p->val+q->val);
        node->left = tree(p->left,q->left);
        node ->right = tree(p->right,q->right);
        return node;
    }
};