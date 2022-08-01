class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n);
        for(auto it:edges){
            indegree[it[1]]++;
        }
        vector<int> temp;
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0){
                temp.push_back(i);
            }
        }
        return temp;
    }
};