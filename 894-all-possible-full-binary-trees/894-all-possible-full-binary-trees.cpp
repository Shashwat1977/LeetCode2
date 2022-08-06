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
    vector<TreeNode*> allPossibleFBT(int n) {
        map<int,vector<TreeNode*>> mp;
        if(n%2 == 0) return {};
        mp[1] = {new TreeNode(0)};
        for(int i = 3;i<=n;i++){
            int total= i-1;
            int left = 1;
            int right = total-1;
            while(left<=total){
                for(auto it:mp[left]){
                    for(auto it2:mp[right]){
                        TreeNode* node = new TreeNode(0);
                        node->left = it;
                        node->right = it2;
                        mp[i].push_back(node);
                    }
                }
                left+=2;
                right-=2;
            }
        }
        return mp[n];
    }
};