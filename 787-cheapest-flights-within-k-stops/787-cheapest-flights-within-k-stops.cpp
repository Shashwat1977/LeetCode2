typedef pair<int, pair<int,int>> pi;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto c : flights){
            adj[c[0]].push_back({c[1],c[2]});
        }
        vector<int> stops(n,INT_MAX);
        vector<int> costs(n,INT_MAX);
        //cost,node,stops
        priority_queue<pi, vector<pi>, greater<pi>> minHeap;
        
        costs[src] = 0;
        stops[src] = 0;
        
        minHeap.push({0,{src,0}});
        
        while(!minHeap.empty()){
            int cost = minHeap.top().first;
            int node = minHeap.top().second.first;
            int stop = minHeap.top().second.second;
            minHeap.pop();
            for(auto c : adj[node]){
                if(c.first == dst){
                    if((costs[c.first] > (cost+c.second)) && (stop <= k)){
                        costs[c.first] = cost + c.second;
                        minHeap.push({costs[c.first],{c.first,stop}});
                    }
                }
                else if((costs[c.first] > (cost+c.second)) || ((stops[c.first]-1) > stop)){
                    costs[c.first] = cost + c.second;
                    
                    stops[c.first] = 1 + stop;
                    minHeap.push({costs[c.first],{c.first,stops[c.first]}});
                }
            }
        }
        int ans =  costs[dst];
        if(ans == INT_MAX)
            ans = -1;
        return ans;
        
        
    }
};