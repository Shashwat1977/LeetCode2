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
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        auto it =  dfs(root,cnt);
        return cnt;
    }
    pair<int,int> dfs(TreeNode* root,int& cnt){
        int sum = root->val;
        int c = 1;
        pair<int,int> l,r;
        if(root->left){
            l = dfs(root->left,cnt);
        }
        if(root->right){
            r = dfs(root->right,cnt);
        }
        pair<int,int> node;
        node.first = sum+l.first+r.first;
        node.second = c + l.second+r.second;
        if(root->val == node.first/node.second){
            cnt++;
        }
        return node;
    }
};