class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> degree(n+1,0);
        for(auto it:trust){
            degree[it[0]]--;
            degree[it[1]]++;
        }
        for(int it = 1;it<=n;it++) {
            if(degree[it] == n-1) return it;
        }
        return -1;
    }
};