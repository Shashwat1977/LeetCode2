class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else{
                    dp[i][j] = min((i>0?dp[i-1][j]:INT_MAX),(j>0?dp[i][j-1]:INT_MAX))+grid[i][j];
                }
            }
        }
        return dp[n-1][m-1];
    }
};