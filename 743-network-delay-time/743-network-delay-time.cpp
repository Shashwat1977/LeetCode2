class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX);
        vector<pair<int,int>> adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        dist[k] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int curr = it.first;
                int d = it.second;
                if(dist[node]+d<dist[curr]){
                    dist[curr] = dist[node]+d;
                    pq.push({dist[curr],curr});
                }
            }
        }
        for(int i = 1;i<=n;i++){
            if(dist[i] == INT_MAX) return -1;
        }
        return *max_element(dist.begin()+1,dist.end());
    }
};