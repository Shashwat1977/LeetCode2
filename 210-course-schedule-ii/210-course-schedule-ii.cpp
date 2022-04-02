class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> adj[n];
        vector<int> indegree(n);
        for(auto it:p){
            adj[it[1]].push_back(it[0]);
        }
        for(int i = 0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i = 0;i<indegree.size();i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> temp;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            temp.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it] == 0)q.push(it);
            }
        }
vector<int> tem;
        if(temp.size() == n) return temp;
        return tem;
        }
};