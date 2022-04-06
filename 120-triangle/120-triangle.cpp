class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        for(int i = 0;i<n;i++){
            dp[n-1][i] = triangle[n-1][i];
        }
        for(int i = n-2;i>=0;i--){
            for(int j = 0;j<=i;j++){
                int up = dp[i+1][j]+triangle[i][j];
                int dd = dp[i+1][j+1]+triangle[i][j];
                dp[i][j] = min(up,dd);
            }
        }
        return dp[0][0];
    }
};