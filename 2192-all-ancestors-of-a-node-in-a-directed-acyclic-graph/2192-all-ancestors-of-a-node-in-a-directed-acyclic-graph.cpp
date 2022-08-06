class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it:edges){
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>> ans;
        for(int i = 0;i<n;i++){
            vector<int> visited(n,0);
            vector<int> temp;
            dfs(i,adj,visited,temp);
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
    void dfs(int node,vector<int> adj[],vector<int>& visited,vector<int>& temp){
        visited[node] =1;
        for(auto it:adj[node]){
            if(!visited[it]){
                temp.push_back(it);
                dfs(it,adj,visited,temp);
            }
        }
    }
};