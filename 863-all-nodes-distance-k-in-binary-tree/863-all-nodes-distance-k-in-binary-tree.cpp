/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int g) {
        unordered_map<TreeNode*,TreeNode*> mp;
        mp[root] = NULL;
        func(mp,root);
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> visited;
        visited[target] = true;
        q.push(target);
        int cur = 0;
        while(!q.empty()){
            int k = q.size();
            if(cur++ == g) break;
            cout<<cur<<endl;
            for(int i = 0;i<k;i++){
                auto node = q.front();
                cout<<node->val<<" ";
                q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(mp[node] != NULL && !visited[mp[node]]){
                    q.push(mp[node]);
                    visited[mp[node]] = true;
                }
            }
        }
            vector<int> ans;
            while(!q.empty()){
                auto node = q.front();q.pop();
                ans.push_back(node->val);
            }
            return ans;
        
    }
    void func(unordered_map<TreeNode*,TreeNode*>& mp,TreeNode* root){

        if(root->left){
            mp[root->left] = root;
            func(mp,root->left);
        }
        if(root->right){
            mp[root->right] = root;
            func(mp,root->right);
        }
    }
};