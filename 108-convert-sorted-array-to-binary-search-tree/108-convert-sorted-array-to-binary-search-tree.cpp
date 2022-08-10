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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return convert(0,n-1,nums);
    }
    TreeNode* convert(int i,int j,vector<int>& nums){
        if(i>j) return NULL;
        int mid = i+(j-i)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = convert(i,mid-1,nums);
        node->right = convert(mid+1,j,nums);
        return node;
    }
};