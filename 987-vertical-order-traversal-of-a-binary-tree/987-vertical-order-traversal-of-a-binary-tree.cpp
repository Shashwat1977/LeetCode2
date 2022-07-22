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
    map<int,map<int,multiset<int>>> mp;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        helper(root,0,0);
        for(auto it:mp){
            vector<int> temp;
            for(auto i:it.second){
                for(auto v:i.second) temp.push_back(v);
            }
            ans.push_back(temp);
        }
        return ans;
    }
    void helper(TreeNode* root,int i,int level){
        if(root == NULL) return;
        mp[i][level].insert(root->val);
        if(root->left!= NULL){
            helper(root->left,i-1,level+1);
        }
        if(root->right != NULL){
            helper(root->right,i+1,level+1);
        }
    }
};