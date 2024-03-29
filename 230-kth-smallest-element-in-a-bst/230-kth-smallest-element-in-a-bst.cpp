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
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        find(root,ans,k);
        return ans;
    }
    void find(TreeNode* root,int& ans,int& k){
        if(root == NULL) return;
        
        find(root->left,ans,k);
        k--;
        if(k == 0) ans = root->val;
        find(root->right,ans,k);
        
    }
};