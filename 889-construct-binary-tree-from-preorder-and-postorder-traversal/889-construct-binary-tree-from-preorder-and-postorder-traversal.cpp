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
    int pre = 0;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i = 0;i<preorder.size();i++){
            mp[postorder[i]] = i;
        }
        int n = preorder.size();
        return construct(preorder,postorder,0,n-1,mp);
    }
    TreeNode* construct(vector<int>& preorder,vector<int>& postorder,int ps,int pe,unordered_map<int,int>& mp){
        if(ps>pe) return NULL;
        TreeNode* node = new TreeNode(preorder[pre]);
        pre++;
        if(ps == pe) return node;
        
        int pi = mp[preorder[pre]];
        node->left = construct(preorder,postorder,ps,pi,mp);
        node->right = construct(preorder,postorder,pi+1,pe-1,mp);
        return node;
    }
};