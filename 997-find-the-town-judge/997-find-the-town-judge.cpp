class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> degree(n+1,0);
        for(auto it:trust){
            degree[it[0]]--;
            degree[it[1]]++;
        }
        for(int i = 1;i<=n;i++){
            if(degree[i] == n-1){
                return i;
            }
        }
        return -1;
    }
};