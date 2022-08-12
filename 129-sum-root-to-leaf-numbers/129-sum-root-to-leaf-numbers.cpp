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
    long long ans = 0;
    int sumNumbers(TreeNode* root) {
        string res = "";
        dfs(root,res);
        return ans;
    }
    void dfs(TreeNode* root,string res){
        if(root == NULL){
            return;
        }
        if(!root->left && !root->right){
            res += to_string(root->val);
            ans += stoi(res);
        }
        dfs(root->left,res+ to_string(root->val));
        dfs(root->right,res+to_string(root->val));
    }
};