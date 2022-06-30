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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            int n = q.size();
            int prev = (level%2)?INT_MAX:INT_MIN;
            for(int i=0;i<n;i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                if(level%2 == cur->val%2){
                    return false;
                }
                if(level%2 && cur->val >= prev){
                    return false;
                }
                if(!(level%2) && prev>= cur->val){
                    return false;
                }
                prev = cur->val;
                if(cur->left != NULL)
                {
                    q.push(cur->left);
                }
                if(cur->right != NULL)
                {
                    q.push(cur->right);
                }
            }
            level++;
        }
        return true;
    }
};