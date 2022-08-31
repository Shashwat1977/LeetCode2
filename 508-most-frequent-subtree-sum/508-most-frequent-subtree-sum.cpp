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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int> mp;
        vector<int> ans;
        int val = dfs(root,mp);
        map<int,vector<int>> mp2;
        for(auto it:mp){
            mp2[it.second].push_back(it.first);
        }
        
        return (--mp2.end())->second;
    }
    int dfs(TreeNode* root,map<int,int>& mp){
        if(root == NULL) return 0;
        int sum = root->val;
        int left = dfs(root->left,mp);
        int right = dfs(root->right,mp);
        int total = sum+left+right;
        mp[total]++;
        return total;
    }
};