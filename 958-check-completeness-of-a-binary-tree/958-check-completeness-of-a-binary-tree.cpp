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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while(!q.empty()){
            int k = q.size();

            for(int i = 0;i<k;i++){
                auto it = q.front();q.pop();
                if(it->left){
                    if(flag)
                    q.push(it->left);
                    else return false;
                }else flag = false;
                if(it->right){
                    if(flag)q.push(it->right);
                    else return false;
                }else flag = false;
            }
        }
        return true;
    }
};