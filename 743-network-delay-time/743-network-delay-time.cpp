class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;
        for(int i = 0;i<n;i++){
            for(auto edge:times){
                int currNode = edge[0];
                int nextNode = edge[1];
                int wt = edge[2];
                if(dist[currNode] != INT_MAX && dist[nextNode]>dist[currNode]+wt){
                    dist[nextNode] = dist[currNode]+wt;
                }
            }
        }
        int mx = 0;
        for(int i = 1;i<dist.size();i++){
            mx = max(mx,dist[i]);
        }
        if(mx == INT_MAX) return -1;
        return mx;
    }
};