class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        for(int i = 0;i<rowIndex+1;i++){
            vector<int> row(i+1,1);
            for(int j = 1;j<i;j++){
                row[j] = res[i-1][j]+res[i-1][j-1];
            }
            res.push_back(row);
        }
        return res[rowIndex];
    }
};