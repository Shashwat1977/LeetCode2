class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> adj[n];
        vector<int> indegree(n);
        vector<int> temp;
        for(auto it:p){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q;
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            temp.push_back(node);
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(temp.size() != n){
            return {};
        }else{
            return temp;
        }
    }
};