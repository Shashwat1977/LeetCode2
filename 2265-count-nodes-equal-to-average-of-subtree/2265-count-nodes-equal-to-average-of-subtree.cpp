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
    int cnt;
    int averageOfSubtree(TreeNode* root) {
        int sum = 0;
        cnt = 0;
        auto ans = helper(root);
        return cnt;
    }
    pair<int,int> helper(TreeNode* root){
        if(root == NULL) return {0,0};
        auto left = helper(root->left);
        auto right = helper(root->right);
        int total = left.first+right.first+root->val;
        int n = left.second+right.second+1;
        if(total/n == root->val) cnt++;
        return {total,n};
    }
};