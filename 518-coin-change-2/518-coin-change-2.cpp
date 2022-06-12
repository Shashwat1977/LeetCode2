class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return helper(n-1,amount,dp,coins);
    }
    int helper(int i,int w,vector<vector<int>>& dp,vector<int>& coins){
        if(i == 0){
            return w%coins[0]==0;
        }
        if(dp[i][w] != -1){
            return dp[i][w];
        }
        int non = helper(i-1,w,dp,coins);
        int pick = 0;
        if(coins[i]<=w){
            pick = helper(i,w-coins[i],dp,coins);
        }
        return dp[i][w] = pick+non;
    }
};