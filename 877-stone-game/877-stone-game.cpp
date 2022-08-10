class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        int val = func(0,n-1,piles,dp);
        if(val>0) return true;
        else return false;
    }
    int func(int i,int j,vector<int>& piles,vector<vector<int>>& dp){
        if(i == j) return piles[i];
        if(dp[i][j] != -1) return dp[i][j];
        int one = piles[i]+func(i+1,j,piles,dp);
        int two = piles[j]+func(i,j-1,piles,dp);
        return dp[i][j] = max(one,two);
    }
};