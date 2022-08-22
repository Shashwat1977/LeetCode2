class Solution {
public:
    vector<int> sub;
    vector<int> sz;
    int total;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        sub.resize(n,0);
        sz.resize(n,0);
        vector<int> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        total = n;
        dfs(0,-1,adj);
        vector<int> ans(n,0);
        solve(0,-1,0,adj,ans);
        return ans;
    }
    void dfs(int src,int par, vector<int> adj[]){
        int s = 1;
        int ans = 0;
        for(auto it:adj[src]){
            if(it != par){
                dfs(it,src,adj);
                s += sz[it];
                ans += sub[it]+sz[it];
            }
        }
        sz[src] = s;
        sub[src] = ans;
}
    void solve(int node,int par,int pans,vector<int> adj[],vector<int>& ans){
        ans[node] = sub[node]+(pans + (total-sz[node]) );
        for(auto it:adj[node]){
            if(it!= par){
                solve(it,node,ans[node]-(sub[it]+sz[it]),adj,ans);
            }
        }
    }
};