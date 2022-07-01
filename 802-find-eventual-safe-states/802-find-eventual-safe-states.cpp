class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        for(int i = 0;i<graph.size();i++){
            for(int j = 0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int> vis(n,0);
        vector<int> res(n,0);
        vector<int> dfsvis(n,0);
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                res[i] = dfs(i,adj,vis,dfsvis,res);
            }
        }
        vector<int> temp;
        for(int i =0;i<n;i++){
            if(res[i] == 0) temp.push_back(i);
        }
        return temp;
    }
    int dfs(int node,vector<int> adj[],vector<int>& vis,vector<int>& dfsvis,vector<int>& res){
        vis[node] = 1;
        dfsvis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,dfsvis,res))
                return res[node] = dfs(it,adj,vis,dfsvis,res);
            }else if(vis[it] && dfsvis[it]){
                return res[node] = 1;
            }
        }
        dfsvis[node] = 0;
        return 0;
    }
};