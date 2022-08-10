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
    int cnt = 0;
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> mp;
        create(root,mp);
        return cnt;
    }
    void create(TreeNode* root,unordered_map<int,int>& mp){
        if(root == NULL) return;
        mp[root->val]++;
        if(root->left == NULL && root->right == NULL){
            if(isPalin(mp)) cnt++;
            
        }
        create(root->left,mp);
        create(root->right,mp);
        mp[root->val]--;
    }
    bool isPalin(unordered_map<int,int>& m){
        int oddCnt = 0;
			for(auto it : m){
				if(it.second % 2 != 0) oddCnt++;
			}
			if(oddCnt <= 1) return true;;
        return false;
    }
};