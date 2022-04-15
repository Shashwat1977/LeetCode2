class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return f(prices,0,0,dp);
    }
    int f(vector<int>& prices,int i,int flag,vector<vector<int>>& dp){
        if(i == prices.size()) return 0;
        if(dp[i][flag] != -1) return dp[i][flag];
        if(flag == 0){
            return dp[i][flag] = max(-prices[i]+f(prices,i+1,1,dp),f(prices,i+1,0,dp));
        }else{
            return dp[i][flag] = max(prices[i]+f(prices,i+1,0,dp),f(prices,i+1,1,dp));
        }
    }
};