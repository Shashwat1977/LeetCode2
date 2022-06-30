class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(n,0);
        dfs(source,adj,visited);
        return visited[destination];
    }
    void dfs(int node,vector<int> adj[],vector<int>& visited){
        visited[node] = 1;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited);
            }
        }
    }
};