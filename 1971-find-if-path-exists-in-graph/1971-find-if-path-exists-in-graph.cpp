class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n,0);
        dfs(source,adj,visited,destination);
        return visited[destination];
    }
    void dfs(int node,vector<int> adj[],vector<int>& visited,int destination){
        visited[node] = 1;
       
        for(auto it:adj[node]){
            if(!visited[it]){
                    dfs(it,adj,visited,destination);
                
            
            
        }
       
    }
    }
};