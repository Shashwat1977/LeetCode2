class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return func(nums.size()-1,dp,nums);
    }
    int func(int i,vector<int>& dp,vector<int>& nums){
        if(i==0) return nums[0];
        if(i<0){
            return 0;
        }
        if(dp[i]!= -1) return dp[i];
        int pick = func(i-2,dp,nums)+nums[i];
        int non = func(i-1,dp,nums);
        return dp[i] = max(pick,non);
    }
};