class Solution {
private:
    int find_parent(int node, vector<int> &parent) {
        if(parent[node] == node)
            return node;
        
        return parent[node] = find_parent(parent[node], parent);
    }
    
    void Union(int u, int v, vector<int> &parent, vector<int> &rank) {
        u = find_parent(u, parent);
        v = find_parent(v, parent);
        
        if(rank[u] < rank[v])
            parent[u] = v;
        else if(rank[v] < rank[u])
            parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
    
public:  
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;
        
        //Making a vector for edges...{dist, node1, node2}
        for(int i = 0; i < n; ++i) { // It's fine if you run till n - 1 as well, doesn't matter!!
            for(int j = i + 1; j < n; ++j)
                edges.push_back({abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), i, j});
        }
        
        sort(edges.begin(), edges.end());
        
        // Finding minimum spanning tree
        int cost = 0;
        vector<int> parent(n);
        vector<int> rank(n, 0);
        
        for(int i = 0; i < n; ++i)
            parent[i] = i;
        
        for(int i = 0; i < edges.size(); ++i) {
            int u = edges[i][1];
            int v = edges[i][2];
            int wt = edges[i][0];
            
            if(find_parent(u, parent) != find_parent(v, parent)) {
                cost += wt;
                Union(u, v, parent, rank);
            }
        }
        
        return cost;
    }
};
