class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i==0){
                    dp[i][j] = matrix[i][j];
                }else{
                    int up = dp[i-1][j];
                    int ld = INT_MAX;
                    int rd = INT_MAX;
                    if(j>0) ld = dp[i-1][j-1];
                    if(j+1<n) rd = dp[i-1][j+1];
                    dp[i][j] = matrix[i][j] + min(up,min(ld,rd));
                }
            }
        }
        int mn = INT_MAX;
        for(int i = 0;i<n;i++){
            mn = min(mn,dp[n-1][i]);
        }
        return mn;
    }
};