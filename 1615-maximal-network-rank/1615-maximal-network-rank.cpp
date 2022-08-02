class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n);
        vector<vector<int>> adj(n,vector<int> (n,0));
        for(auto it:roads){
            degree[it[1]]++;
            degree[it[0]]++;
            adj[it[1]][it[0]] = 1;
            adj[it[0]][it[1]] = 1;
        }
        int mx = INT_MIN;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i != j){
                    mx = max(mx,degree[i]+degree[j] - adj[i][j]);
                }
            }
        }
        return mx;
    }
};