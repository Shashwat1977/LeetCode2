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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if(root == NULL) return res;
        q.push(root);
        while(!q.empty()){
            int k = q.size();
            int mx = INT_MIN;
            for(int i = 0;i<k;i++){
                TreeNode* node = q.front();
                mx = max(mx,node->val);
                q.pop();
                if(node->left != NULL)q.push(node->left);
                if(node->right != NULL)q.push(node->right);
            }
             res.push_back(mx);
        }
        return res;
    }
};