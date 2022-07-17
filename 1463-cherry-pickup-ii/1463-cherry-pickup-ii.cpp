class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(r,vector<vector<int>> (m,vector<int>(m,-1)));
        return func(0,0,m-1,r,m,grid,dp);
    }
    int func(int i,int j1,int j2,int r,int m,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        if(j1<0 || j2<0 || j1>=m || j2>=m) return -1e8;
        if(i==r-1){
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        int maxi = 0;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2 = -1;dj2<=1;dj2++){
                int val = 0;
                if(j1 == j2){
                    val = grid[i][j1];
                }else{
                    val = grid[i][j1]+grid[i][j2];
                }
                maxi = max(maxi,val+func(i+1,j1+dj1,j2+dj2,r,m,grid,dp));
            }
        }
        return dp[i][j1][j2] = maxi;
    }
};