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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        help(root,inorder);
        int s = 0;
        int e = inorder.size()-1;
        return helper(inorder,s,e);
    }
    void help(TreeNode* root,vector<int>& inorder){
        if(root == NULL) return;
        help(root->left,inorder);
        inorder.push_back(root->val);
        help(root->right,inorder);
    }
    TreeNode* helper(vector<int>& inorder,int s,int e){
        if(s>e) return NULL;
        int mid = (s+e)/2;
        TreeNode* node = new TreeNode(inorder[mid]);
        node->left = helper(inorder,s,mid-1);
        node->right = helper(inorder,mid+1,e);
        return node;
    }
};