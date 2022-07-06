class Solution {
public:
    vector<pair<int,int>> pos = {{1,0},{-1,0},{0,1},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = size(grid), m = size(grid[0]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==2)
                    q.push({i,j});
          int ans = 0;
          while(!q.empty()){
              int t = size(q);
              ans++;
              while(t--){
                 auto [cur_x,cur_y] = q.front();q.pop();
                 for(auto [dx,dy]:pos){
                     int x = cur_x + dx;
                     int y = cur_y + dy;
                     if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==1)
                         q.push({x,y}),grid[x][y] = 2;
                      }
              }
          }
         for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==1) 
                    return -1;
                    return max(0,ans-1);
    }
};