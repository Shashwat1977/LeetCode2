class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<int> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int> q;
        vector<int> dist(n);
        vector<int> visited(n);
        
        dist[0] = 0;
        q.push(0);
        visited[0] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:adj[node]){
                if(!visited[it]){
                    dist[it] = dist[node]+1;
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        int lastTimeMessageReceived = 0, lastTimeMessageSent, times = INT_MAX;

        // finding last time a data server sent a message to main server.
        for(int i = 1; i < n; i++) {
            times = (2*dist[i]-1) / patience[i];

            lastTimeMessageSent = times * patience[i];

            lastTimeMessageReceived = max(lastTimeMessageSent + dist[i]*2, lastTimeMessageReceived);

        }

        return lastTimeMessageReceived + 1;
    }
};