class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return func(0,prices,dp,1);
    }
    int func(int i,vector<int>& prices,vector<vector<int>>& dp,int buy){
        if(i == prices.size()) return 0;
        if(dp[i][buy]!= -1) return dp[i][buy];
        if(buy){
            return dp[i][buy]=max(-prices[i]+func(i+1,prices,dp,0),func(i+1,prices,dp,1));
        }else{
            return dp[i][buy]=max(prices[i]+func(i+1,prices,dp,1),func(i+1,prices,dp,0));
        }
    }
};