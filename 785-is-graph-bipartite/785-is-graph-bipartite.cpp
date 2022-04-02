class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int size = graph.size();
        vector<int> color(size,0);
        queue<int> q;
        for(int i = 0;i<size;i++){
            if(color[i]==0){
                q.push(i);
                color[i]=1;
                while(!q.empty()){
                    int val = q.front();
                    q.pop();
                    for(int it:graph[val]){
                        if(color[it] == 0){
                            q.push(it);
                            color[it] = -color[val];
                        }else if(color[it] == color[val]) return false;
                        
                    }
                }
            }
        }
        return true;
    }
};