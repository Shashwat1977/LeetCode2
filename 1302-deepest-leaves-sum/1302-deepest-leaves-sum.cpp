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
    int deepestLeavesSum(TreeNode* root) {
        long long ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int k = q.size();
            ans =0;
            for(int i = 0;i<k;i++){
                auto it = q.front();q.pop();
                ans += it->val;
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
            
        }
        return ans;
    }
};