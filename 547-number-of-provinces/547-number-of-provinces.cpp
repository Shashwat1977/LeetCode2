class Solution {
public:
    int findCircleNum(vector<vector<int>>& edges) {
        int cnt = 0;
        int n = edges.size();
        vector<int> visited(n,0);
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                dfs(i,edges,visited);
                cnt++;
            }
        }
        return cnt;
    }
    void dfs(int node,vector<vector<int>>& edges,vector<int>& visited){
        visited[node] = 1;
        for(int i = 0;i<edges[node].size();i++){
            if(!visited[i] && edges[node][i]){
                dfs(i,edges,visited);
            }
        }
    }
};