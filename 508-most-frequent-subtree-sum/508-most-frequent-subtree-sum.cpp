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
        map<long long,int> mp;
       int val =  helper(root,mp);
        map<int,vector<int>> mp2;
        for(auto it:mp){
            mp2[it.second].push_back(it.first);
            
        }
        return (*mp2.rbegin()).second;
    }
    int helper(TreeNode* root,map<long long,int>& mp){
        if(root == NULL) return 0;
        int ans = root->val;
        ans += helper(root->left,mp);
        ans += helper(root->right,mp);
        mp[ans]++;
        return ans;
    }
};