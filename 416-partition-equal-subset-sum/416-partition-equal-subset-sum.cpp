class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2 != 0) return false;
        int n = nums.size();
        sum/=2;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return f(nums.size()-1,sum,nums,dp);
    }
    bool f(int i,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(target == 0) return true;
        if(i == 0) return nums[0] == target;
        if(dp[i][target] != -1) return dp[i][target];
        bool non = f(i-1,target,nums,dp);
        bool pick = false;
        if(nums[i]<= target){
            pick = f(i-1,target-nums[i],nums,dp);
        }
        return dp[i][target] = pick||non;
    }
};