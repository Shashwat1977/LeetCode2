class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m  = grid[0].size();
        int mx = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    mx = max(mx,dfs(i,j,grid));
                }
            }
        }
        return mx;
    }
    int dfs(int r,int c,vector<vector<int>>& grid){
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c] == 0){
            return 0;
        }
        int count = 1;
        grid[r][c] = 0;
        count += dfs(r+1,c,grid);
        count += dfs(r,c-1,grid);
        count += dfs(r-1,c,grid);
        count += dfs(r,c+1,grid);
        return count;
    }
};