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
    int ans;
    int maxAncestorDiff(TreeNode* root) {
        search(root,INT_MIN,INT_MAX);
        return ans;
    }
    void search(TreeNode* root,int mx,int mn){
        if(root== NULL){
            ans = max(ans,abs(mx-mn));
            return;
        }
        int val = root->val;
        mx = max(val,mx);
        mn = min(val,mn);
        cout<<root->val<<" "<<mx<<" "<<mn<<endl;
        search(root->left,mx,mn);
        search(root->right,mx,mn);
    }
};