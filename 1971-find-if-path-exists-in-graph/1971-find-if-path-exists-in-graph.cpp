class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n == 1 || edges.size() == 0 || source ==destination) return true;
        queue<int> q;
        vector<int> visited(n,0);
        q.push(source);
        vector<int> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    visited[node] = 1;
                    for(auto it:adj[node]){
                        if(!visited[it]){
                        if(it == destination) return true;
                        q.push(it);
                        }
                    }
                }
            return false;
    }
};