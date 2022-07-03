class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int find(int x){
        if(x == parent[x]) return x;
        else return parent[x] = find(parent[x]);
    }
    void Union(int a,int b){
        a = find(a);
        b = find(b);
        if(a != b){
            parent[b] = a;
            if(size[a]<=size[b]){
                swap(a,b);
            }
            size[a]+=size[b];
        }
    }
    void make(int x){
        parent[x] = x;
        size[x] = 1;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 1;i<=n;i++){
            make(i);
        }
        vector<int> ans(2);
        for(auto it:edges){
            int x = it[0];
            int y = it[1];
            if(find(x) != find(y)){
                Union(x,y);
            }else{
                ans[0] = x;
                ans[1] = y;
            }
        }
        return ans;
    }
};