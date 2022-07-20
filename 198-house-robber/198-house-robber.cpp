class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return func(nums.size()-1,nums,dp);
    }
    int func(int i,vector<int>& nums,vector<int>& dp){
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(func(i-1,nums,dp),nums[i]+func(i-2,nums,dp));
    }
};