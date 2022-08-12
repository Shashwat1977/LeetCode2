class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        
        vector<int> adj[n];
        int src = 0;
        for(int i = 0;i<parents.size();i++){
            if(parents[i] == -1) src = i;
            else adj[parents[i]].push_back(i);
        }
        vector<long long> ans(n);
        dfs(src,ans,adj);
        long long cnt=*max_element(ans.begin(),ans.end());
    int res=count(ans.begin(),ans.end(),cnt);
    return res;
    }
    int dfs(int node,vector<long long>& ans,vector<int> adj[]){
        long long  k=0,temp=1;
    for(auto it : adj[node]){
            int val=dfs(it,ans,adj);
            k+=val;
            if(val!=0)
                temp*=val;
        
    }
    k++;
        int n = ans.size();
    if(n-k>0){
        temp*=(n-k);
    }
    ans[node]=temp;
    return k;
    }
};