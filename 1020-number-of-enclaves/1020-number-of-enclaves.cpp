class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i == 0||i == n-1 || j == 0 || j==m-1){
                    dfs(i,j,n,m,grid);
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }
    void dfs(int i,int j,int r,int c,vector<vector<int>>& grid){
        if(i<0 ||  i>=r || j<0 || j>=c || grid[i][j] == 0) return;
        grid[i][j] = 0;
        dfs(i+1,j,r,c,grid);
        dfs(i-1,j,r,c,grid);
        dfs(i,j+1,r,c,grid);
        dfs(i,j-1,r,c,grid);
    }
};