class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();int mx = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                int area = count(grid,i,j);
                mx = max(mx,area);
            }
        }
        return mx;
    }
    int count(vector<vector<int>>& grid,int i,int j){
        if(i<0 || j<0 || i>grid.size()-1 || j>grid[0].size()-1){
            return 0;
        }
        if( grid[i][j]==0) return 0;
        int c = 1;
        grid[i][j] = 0;
        c+= count(grid,i+1,j);
        c+= count(grid,i-1,j);
        c+=count(grid,i,j+1);
        c+=count(grid,i,j-1);
        return c;
    }
};