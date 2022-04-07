class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        for(int i = 0;i<n;i++){
            dp[0][i] = matrix[0][i];
        }
        for(int i = 1;i<n;i++){
            for(int j = 0;j<n;j++){
                int up = dp[i-1][j]+matrix[i][j];
                int left = INT_MAX;
                int right = INT_MAX;
                if(j-1>=0){
                    left = dp[i-1][j-1];
                }
                if(j+1<n){
                    right = dp[i-1][j+1];
                }
                int m = min(left,right)+matrix[i][j];
                dp[i][j] = min(up,m);
            }
        }
        int mn = INT_MAX;
        for(int i = 0;i<n;i++){
            mn = min(mn,dp[n-1][i]);
        }
        return mn;
    }
};