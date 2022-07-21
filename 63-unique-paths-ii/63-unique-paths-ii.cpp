class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int n= g.size();
        int m = g[0].size();
        vector<int> prev(m,0);
        for(int i = 0;i<n;i++){
            vector<int> temp(m,0);
            for(int j = 0;j<m;j++){
                if(g[i][j] == 1) temp[j] = 0;
                else{
                    if(i == 0 && j==0) temp[j] = 1;
                    else{
                        temp[j] = ((i>0)?prev[j]:0)+((j>0)?temp[j-1]:0);
                    }
                }
            }
            prev = temp;
        }
        return prev[m-1];
    }
};