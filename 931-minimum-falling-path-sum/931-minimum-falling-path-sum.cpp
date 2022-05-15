class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int dp[n][n];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i == 0) dp[i][j] = matrix[i][j];
                else{
                    int ld = INT_MAX;
                    int rd = INT_MAX;
                    if(j>0) ld = dp[i-1][j-1];
                    if(j<n-1) rd = dp[i-1][j+1];
                    dp[i][j] = min(ld,min(rd,dp[i-1][j]))+matrix[i][j];
                }
            }
        }
        int mx = INT_MAX;
        for(int i = 0;i<n;i++){
            mx = min(mx,dp[n-1][i]);
        }
        return mx;
    }
};