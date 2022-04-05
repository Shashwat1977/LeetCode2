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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root == NULL) return res;
        q.push(root);
        int i = 1;
        while(!q.empty()){
            int k = q.size();
            vector<int> temp;
            for(int i = 0;i<k;i++){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left != NULL) q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
            }
            if(i%2 == 0) reverse(temp.begin(),temp.end());
            i++;
            res.push_back(temp);
        }
        return res;
    }
};