class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
    void dfs(int r,int c,vector<vector<char>>& grid){
        int row = grid.size();
        int col = grid[0].size();
        if(r<0 || r>=row || c<0 || c>=col || grid[r][c] != '1'){
            return;
        }
        if(grid[r][c] == '0') return;
        grid[r][c] = 0;
        dfs(r+1,c,grid);
        dfs(r-1,c,grid);
        dfs(r,c+1,grid);
        dfs(r,c-1,grid);
    }
};