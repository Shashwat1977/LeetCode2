class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> adj[n+1];
        
        for(auto it:p) adj[it[1]].push_back(it[0]);
        vector<int> indegree(n);
        for(int i = 0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i = 0;i<indegree.size();i++){
            if(indegree[i] == 0) q.push(i);
        }
        int count = q.size();
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){q.push(it);count++;}
            }
        }
        return count == n;
    }
};