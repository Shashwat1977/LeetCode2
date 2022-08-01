class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> degree(n);
        for(auto it:roads){
            degree[it[0]]++;
            degree[it[1]]++;
        }
        sort(degree.begin(),degree.end());
        long long res = 0;
        for(int i = 0;i<degree.size();i++){
            res += degree[i]*(i+1);
        }
        return res;
    }
};