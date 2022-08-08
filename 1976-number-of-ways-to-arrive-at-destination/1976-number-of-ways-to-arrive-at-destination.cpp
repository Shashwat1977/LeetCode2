class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
       
        /*This is the preparation part of this problem, here we are simply 
		converting given data in the form of adjacency list which is required to
		run Dijkstra's algorithm */
        vector<pair<long long int, long long int>> adj[201];
        for(int i = 0; i < roads.size(); i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
		
        priority_queue<pair<long long, long long>> pq;
        pq.push({0, 0});
        vector<long long> distance(201, LLONG_MAX);
		// Following is the dp array which stores the number of ways to reach a node
        vector<long long> paths(201, 0); 
        vector<long long> visited(201, 0);
      
        distance[0] = 0; //because we are starting from 0
        paths[0] = 1;
        
        while(!pq.empty())
        {
            pair<long long, long long> p = pq.top(); pq.pop();
            long long dist = -p.first;
            int u = p.second;
            if(visited[u]) continue;
            visited[u] = 1;
          
            for(int i = 0; i < adj[u].size(); i++)
            {
                int v = adj[u][i].first;
                long long w = adj[u][i].second;
                
				/*this means that we've found a better(less time consuming) 
				way to reach v, now this better way will prevail and 
				we now don't care about past ways therefore total number 
				of ways to reach v is simply equal to the total number of ways 
				to reach its parent which is u */
                if(dist + w < distance[v]) 
                {
                    distance[v] = dist + w;
                    pq.push({-(dist+w), v});
                    paths[v] = paths[u];
                }
				/*here we have a way to reach v which is taking same amount 
				of time	as the optimal path but this time parent of v 
				is different therefore we ways to reach u to current ways 
				of reaching v*/
                else if(dist+w == distance[v])
                {
                    paths[v] = (paths[v] + paths[u])%1000000007;
                    pq.push({-(dist+w), v});
                }
            }
        }
       
        return (int) paths[n-1];
    }
};