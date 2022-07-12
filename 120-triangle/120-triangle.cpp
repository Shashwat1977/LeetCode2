class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return ans(0,0,triangle,dp);
    }
    int ans(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(i == triangle.size()-1) return triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j] = min(ans(i+1,j,triangle,dp),ans(i+1,j+1,triangle,dp))+triangle[i][j];
        return dp[i][j];
    }
};