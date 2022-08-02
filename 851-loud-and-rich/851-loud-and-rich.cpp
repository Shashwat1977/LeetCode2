class Solution {
public:
        vector<int> ans;
    int dfs(int u , vector<int> adj[] , vector<int> &q) {
        if(ans[u] != INT_MAX) return ans[u];
        int minm = q[u];
        int res = u;
        for(int v : adj[u]) {
            int x = dfs(v , adj , q);
            if(minm > q[x]) {
                minm = q[x];
                res = x;
            }
        }
        return ans[u] = res;
    }
    vector<int> loudAndRich(vector<vector<int>> &r , vector<int> &q) {
        int n = q.size();
        ans.clear();
        ans.resize(n , INT_MAX);
        vector<int> adj[n];
        for(int i=0 ; i<r.size() ; i++) {
            int u = r[i][0];
            int v = r[i][1];
            adj[v].push_back(u);
            // adj[u].push_back(v);
        }
        for(int i=0 ; i<n ; i++) {
            dfs(i , adj , q);
        }
        return ans;
    }

};