class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> adj[n];
        for(int i = 0;i<rooms.size();i++){
            for(int j = 0;j<rooms[i].size();j++){
                adj[i].push_back(rooms[i][j]);
            }
        }
        vector<int> vis(n,0);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
           int node = q.front();
            vis[node] = 1;
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        for(int i = 0;i<n;i++){
            if(vis[i] == 0) return false;
        }
        return true;
    }
};