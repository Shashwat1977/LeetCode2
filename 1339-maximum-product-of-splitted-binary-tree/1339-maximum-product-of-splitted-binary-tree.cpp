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
static int MOD=1e9+7;
class Solution {
public:
    long long mx;
    int maxProduct(TreeNode* root) {
        long long sum = 0;
        getsum(root,sum);
        cout<<sum<<endl;
        long long curr = 0;
        mx = 0;
        int ans = getprod(root,sum)%(100000007);
        return mx%(MOD);
    }
    long long getprod(TreeNode* root,long long sum){
        if(root == NULL) return 0;
        long long curr = 0;
        curr += getprod(root->left,sum);
        curr += getprod(root->right,sum);
        curr += root->val;
        sum -= curr;
        mx = max(mx,sum*curr);
        return curr;
    }
    void getsum(TreeNode* root,long long &sum){
        if(root == NULL) return;
        getsum(root->left,sum);
        sum += root->val;
        getsum(root->right,sum);
    }
};