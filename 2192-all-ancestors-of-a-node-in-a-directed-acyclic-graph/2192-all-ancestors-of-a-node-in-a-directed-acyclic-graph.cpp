class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> q;
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<set<int>> ancestors(n);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:adj[node]){
                ancestors[it].insert(ancestors[node].begin(),ancestors[node].end());
                ancestors[it].insert(node);
            
            if(--indegree[it] == 0){
                q.push(it);
            }
            }
            
        }
        vector<vector<int>> ans(n);
        for (int i=0; i<ans.size(); i++) {
            ans[i] =  vector<int>{ancestors[i].begin(), ancestors[i].end()};
        }
        
        return ans;

    }
};