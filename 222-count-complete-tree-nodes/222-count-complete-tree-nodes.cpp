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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        TreeNode* temp = root;
        int lh = leftheight(temp);
        int rh = rightheight(temp);
        if(lh == rh){
            return (1<<lh)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    int leftheight(TreeNode* root){
        int lh = 0;
        while(root!=NULL){
            root=root->left;
            lh++;
        }
        return lh;
    }
    int rightheight(TreeNode* root){
        int rh = 0;
        while(root != NULL){
            root = root->right;
            rh++;
        }
        return rh;
    }
};