class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(n);
        int ans = dfs(0,adj,visited,hasApple);
        return ans>0?ans-2:0;
    }
    int dfs(int node,vector<int> adj[],vector<int>& visited,vector<bool>& hasApple){
        visited[node] = 1;
        int ans = 0;
        for(auto it:adj[node]){
            if(!visited[it]){
                ans += dfs(it,adj,visited,hasApple);
            }
        }
        if(hasApple[node] || ans>0) ans+=2;
        return ans;
    }
};