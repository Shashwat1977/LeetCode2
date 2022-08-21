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
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* target;
        unordered_map<TreeNode*,TreeNode*> mp;
        mp[root] = NULL;
        func(mp,root,start,target);
        queue<TreeNode*> q;
        q.push(target);
        int cnt = 0;
        unordered_map<TreeNode*,bool> visited;
        while(!q.empty()){
            int k = q.size();
            cnt++;
            for(int i = 0;i<k;i++){
                auto it = q.front();q.pop();
                visited[it] = 1;
                
                if(it->left && !visited[it->left]){
                    q.push(it->left);
                }
                if(it->right && !visited[it->right]){
                    q.push(it->right);
                }
                if(mp[it] != NULL && !visited[mp[it]]){
                    q.push(mp[it]);
                    visited[mp[it]] = true;
                }
            }
        }
        return cnt-1;
    }
    void func(unordered_map<TreeNode*,TreeNode*>& mp,TreeNode* root,int start,TreeNode*& target){
        if(root->val == start) target = root;
        if(root->left){
            mp[root->left] = root;
            func(mp,root->left,start,target);
        }
        if(root->right){
            mp[root->right] = root;
            func(mp,root->right,start,target);
        }
    }
};