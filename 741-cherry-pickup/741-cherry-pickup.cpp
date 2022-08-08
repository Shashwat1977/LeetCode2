class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n= grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (n,vector<int> (n,-1)));
        return max(0,func(0,0,0,grid,dp));
    }
    int func(int r1,int c1,int c2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        int r2 = r1+c1-c2;
        if(r1 >=grid.size() || r2>=grid.size() || c1>=grid[0].size() || c2>=grid[0].size() || grid[r1][c1] ==  -1 || grid[r2][c2] == -1){
            return -1e8;
        }
        if(r1 == grid.size()-1 && c1 == grid.size()-1) return grid[r1][c1];
        if(dp[r1][c1][c2] != -1) return dp[r1][c1][c2];
        int ans = 0;
        ans += grid[r1][c1];
        if(r1 != r2){
            ans += grid[r2][c2];
        }
        ans += max({func(r1+1,c1,c2,grid,dp),func(r1,c1+1,c2,grid,dp),func(r1+1,c1,c2+1,grid,dp),func(r1,c1+1,c2+1,grid,dp)});
        return dp[r1][c1][c2] = ans;
    }
};