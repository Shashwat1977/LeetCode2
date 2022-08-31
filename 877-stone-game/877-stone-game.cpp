class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int i = 0;
        int n = piles.size();
        int j = n-1;
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return dp[0][n-1];
    }
    int helper(int i,int j,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        if(helper(i+1,j,dp)){
            ans = 1;
        }
        if(helper(i,j-1,dp)){
            ans = 1;
        }
        return dp[i][j] = ans;
    }
};