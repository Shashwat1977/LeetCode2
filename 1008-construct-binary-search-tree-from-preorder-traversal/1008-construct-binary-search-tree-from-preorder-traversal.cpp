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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> pre = preorder;
        sort(preorder.begin(),preorder.end());
        vector<int> inorder = preorder;
        map<int,int> mp;
        for(int i = 0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return tree(pre,0,pre.size()-1,inorder,0,inorder.size()-1,mp);
    }
    TreeNode* tree(vector<int>& pre,int ps,int pe,vector<int>& inorder,int is,int ie,map<int,int>& mp){
        if(ps>pe || is>ie) return NULL;
        
        int rt = mp[pre[ps]];
        TreeNode* root = new TreeNode(pre[ps]);
        int len = rt-is;
        root->left = tree(pre,ps+1,ps+len,inorder,is,rt-1,mp);
        root->right = tree(pre,ps+len+1,pe,inorder,rt+1,ie,mp);
        return root;
    }
};