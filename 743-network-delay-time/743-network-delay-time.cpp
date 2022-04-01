class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> cost(n+1,INT_MAX);
        vector<pair<int,int>> adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        cost[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            int curr = pq.top().second;
            int cos = pq.top().first;
            pq.pop();
            for(auto it:adj[curr]){
                int node = it.first;
                int wt = it.second;
                if(cost[node]>cost[curr]+wt){
                    cost[node] = cost[curr]+wt;
                    pq.push({cost[node],node});
                }
            }
        }
        int mx = 0;
        for(int i = 1;i<cost.size();i++){
            mx = max(mx,cost[i]);
        }
        if(mx == INT_MAX) return -1;
        return mx;
    }
};