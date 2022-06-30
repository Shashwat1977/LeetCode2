class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i = 0;i<n;i++){
            if(manager[i] != -1){
                adj[manager[i]].push_back(i);
            }
        }
        return dfs(headID,adj,informTime);
    }
    int dfs(int node,vector<int> adj[],vector<int>& informTime){
        int time = 0;
        for(auto it:adj[node]){
            time = max(time,dfs(it,adj,informTime));
        }
        return time+informTime[node];
    }
};