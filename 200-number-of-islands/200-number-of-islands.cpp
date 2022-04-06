class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                if(grid[i][j] == '1'){
                    dfs(i,j,grid);
                    count+=1;
                }
        }
    }
        return count;
    }
    void dfs(int i,int j,vector<vector<char>>& grid){
        int row = grid.size();
        int col = grid[0].size();
        if(i<0 || i>= row||j<0||j>=col || grid[i][j] != '1'){
            return;
        }
        grid[i][j] = 0;
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
};