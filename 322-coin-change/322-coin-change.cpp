class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int ans = helper(n-1,coins,amount,dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
    int helper(int i,vector<int>& coins,int target,vector<vector<int>>& dp){
        if(target<0) return 1e9;
        if(target == 0) return 0;
        if(i == 0){
            if(target%coins[i] == 0) return target/coins[i];
            else return 1e9;
        }
        if(dp[i][target]!= -1) return dp[i][target];
        int pick = helper(i,coins,target-coins[i],dp)+1;
        int non = helper(i-1,coins,target,dp);
        return dp[i][target] = min(pick,non);
    }
};