class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n,0);
        vector<int> adj[n];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj,visited);
                cnt++;
            }
        }
        return cnt;
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