class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        vector<int> visited(n,0);
        vector<int> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(s,adj,visited);
        if(visited[d] == 1){
            return true;
        }else{
            return false;
        }
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