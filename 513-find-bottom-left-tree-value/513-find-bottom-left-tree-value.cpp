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
    int findBottomLeftValue(TreeNode* root) {
        int ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int k = q.size();
            ans = q.front()->val;
            for(int i =0 ;i<k;i++){
                auto it = q.front();q.pop();
                if(it->left){
                    q.push(it->left);
                }
                if(it->right){
                    q.push(it->right);
                }
            }
        }
        return ans;
    }
};