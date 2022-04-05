class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return recur(nums,dp,n-1);
    }
    int recur(vector<int>& nums,vector<int>& dp,int i){
        if(i == 0) return nums[0];
        if(i<0) return 0;
        if(dp[i] != -1) return dp[i];
        int one = nums[i]+recur(nums,dp,i-2);
        int two  = recur(nums,dp,i-1);
        return dp[i] = max(one,two);
    }
};