class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> adj[n];
        vector<int> indegree(n);
        for(auto it:p){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q;
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int cnt = q.size();
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                    cnt++;
                }
            }
        }
        return cnt == n;
    }
};