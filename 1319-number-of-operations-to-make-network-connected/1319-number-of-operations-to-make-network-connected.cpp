class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<int> adj[n];
        int k = connections.size();
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int cnt = 0;
        vector<int> visited(n,0);
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj,visited);
                cnt++;
            }
        }
        return cnt-1;
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