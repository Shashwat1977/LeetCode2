class Solution {
public:
    vector<pair<int,int>> adj[101];
    vector<pair<int,int>> ans;
    bool static cmp(pair<int,int> a, pair<int,int> b)
    {
        if(a.first==b.first)
            return a.second>b.second;
        return a.first<b.first;
    }
    void dji(int node, int n,int th )
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n,INT_MAX);
        dist[node]=0;
        pq.push({0,node});
        while(!pq.empty())
        {
            int distprev= pq.top().first;
            int prev = pq.top().second;
            pq.pop();
            for(auto it: adj[prev])
            {
                int next = it.first;
                int nextdist= it.second;
                if(dist[next]>dist[prev]+nextdist)
                {
                    dist[next]=dist[prev]+nextdist;
                    pq.push({dist[next],next});
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(i!=node && dist[i]<=th)
                cnt++;
        }
        ans.push_back({cnt,node});
        
    }
    int findTheCity(int n, vector<vector<int>>& edges, int th) {
        for(int i =0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        for(int i =0;i<n;i++)
        {
            dji(i,n,th);
        }
        sort(ans.begin(),ans.end(),cmp);
        for(int i =0;i<n;i++)
            cout<<ans[i].first<<" ";
        return ans[0].second;
    }
};
