class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        vector<int> prefix(n);
        prefix[0] = stones[0];
        for(int i = 1;i<n;i++){
            prefix[i] = prefix[i-1]+stones[i];
        }
        return func(0,n-1,prefix,dp);
    }
    int func(int i,int j,vector<int>& prefix,vector<vector<int>>& dp){
        if(i==j) return 0; // No other stone to pick 
        if(dp[i][j] != -1) return dp[i][j];
        int ls = prefix[j-1] - (i==0?0:prefix[i-1]); // sum after removing the last stone
        int rs = prefix[j] - (prefix[i]); // sum after removing the first stone
        return dp[i][j] = max(ls - func(i,j-1,prefix,dp),rs-func(i+1,j,prefix,dp));
        
    }
};