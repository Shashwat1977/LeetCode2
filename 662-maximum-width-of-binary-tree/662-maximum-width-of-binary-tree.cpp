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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans = INT_MIN;
        while(!q.empty()){
            int k = q.size();
            int min = q.front().second;
            int first,last;
            for(int i = 0;i<k;i++){
                int si = q.front().second - min;
                TreeNode* node = q.front().first;
                q.pop();
                if(i == 0) first = si;
                if(i == k-1) last = si;
                if(node->left) q.push({node->left,(long long) 2*si+1});
                if(node->right) q.push({node->right,(long long) 2*si+2});

            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};