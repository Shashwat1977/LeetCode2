class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return findPath(m-1,n-1,dp);
    }
    int findPath(int i,int j,vector<vector<int>>& dp){
        if(i == 0 && j == 0){
            return 1;
        }
        if(i<0 || j<0) return 0;
        if(dp[i][j]!= -1) return dp[i][j];
        dp[i][j] = findPath(i-1,j,dp)+findPath(i,j-1,dp);
        return dp[i][j];
    }
};