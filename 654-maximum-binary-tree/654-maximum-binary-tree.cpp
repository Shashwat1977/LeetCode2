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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size()-1;
        return tree(0,n,nums);
    }
    TreeNode* tree(int i,int j,vector<int>& nums){
        if(i>j){
            return NULL;
        }
        int ind  = i;
        for(int s = i;s<=j;s++){
            if(nums[s]>nums[ind]){
                ind = s;
            }
        }
        TreeNode* node = new TreeNode(nums[ind]);
        node->left = tree(i,ind-1,nums);
        node->right = tree(ind+1,j,nums);
        return node;
    }
};