class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {

        vector<pair<int,int>> adj[n]; // <node, edge color>
        for(auto& e : redEdges){
            int u = e[0], v = e[1];
            adj[u].push_back({v, 0}); // 0 is for red colored edges
        }
        for(auto& e : blueEdges){
            int u = e[0], v = e[1];
            adj[u].push_back({v, 1}); // 1 is for blue colored edges
        }

        /*
        dist[0][i] -> shortest alterating path from node [0] to node [i]
                      such that arrived at node [i] using a red edge (i.e. the last edge taken to reach [i] was red)         
                       
        dist[1][i] -> shortest alternating path from node[0] to node [i]
                      such that arrived at node [i] using a blue edge (i.e. the last edge taken to reach [i] was blue)
       */
        vector<vector<int>> dist (2, vector<int>(n, INT_MAX)); 

        queue<pair<int,int>> q; // < node, color of last edge taken to reach that node >
        q.push({0,0}); q.push({0,1}); 
        dist[0][0] = 0;
        dist[1][0] = 0;

        while(q.size()){
            int qsize = q.size();
            while(qsize--){

                auto [currNode, currColor] = q.front();
                q.pop();
                int currDist = dist[currColor][currNode];
                

                for(auto& [adjNode, adjColor] : adj[currNode]){
                    if(adjColor == currColor) continue;

                    if(dist[adjColor][adjNode] != INT_MAX) continue;

                    dist[adjColor][adjNode] = 1 + currDist;
                    q.push({adjNode, adjColor});
                    
                }
            }
        }

        vector<int> ans(n, 0);
        for(int i=0;i<n;i++){
            int minDist = min(dist[0][i], dist[1][i]);
            if(minDist == INT_MAX) ans[i] = -1;
            else ans[i] = minDist;
        }

        return ans;

    }
};