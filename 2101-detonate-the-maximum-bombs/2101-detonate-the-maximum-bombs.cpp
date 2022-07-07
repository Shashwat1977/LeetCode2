class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
  vector<vector<int>>adj(bombs.size());
  // Creating the adjacancy list for a directed graph. The graph will contain bombs as nodes and each node will have a directed edge to the bombs in it's range
  for(int i = 0;i < bombs.size(); i++)
  {
      for(int j = 0;j < bombs.size(); j++)
      {
          if(j == i)
          {
              continue;
          }
          if(dis(bombs[i][0], bombs[i][1], bombs[j][0], bombs[j][1]) <= bombs[i][2])  // If distance between two centres is less than radius of current bomb it will lie in it's range so push it in the adjacancy list of current bomb
          {
              adj[i].push_back(j);
          }
      }
  }
  int ans = INT_MIN;
  for(int i = 0;i < bombs.size(); i++)   // We'll run bfs function from every bomb and store maximum (Bfs function will tell how many bombs we could reach from the current bomb)
  {
      vector<int>vis(bombs.size(), 0);
      ans = max(ans, bfs(adj, vis, i));
  }
  return ans;
}

double dis(int x1, int y1, int x2, int y2){  // Function to calculate distance between two centres
  return pow((pow(x2-x1, 2) + pow(y2-y1, 2)), 0.5);
}

int bfs(vector<vector<int>>& adj, vector<int>& vis, int node)  {     
// bfs function will return the total nodes we can reach from a current node
  queue<int>q;
  vis[node] = 1;
  q.push(node);
  int count = 1;
  while(!q.empty())
  {
      int front = q.front();
      q.pop();
      for(auto i: adj[front])
      {
          if(vis[i] != 1)
          {
              vis[i] = 1;
              q.push(i);
              count++;
          }
      }
  }
  return count;
}
};
