class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        bool flag ;
        for(int i = left;i<=right;i++){
            flag = false;
            for(auto it:ranges){
                if(i>=it[0] && i<=it[1]){
                    flag = true;
                    break;
                }
            }
            if(flag) continue;
            else return false;
        }
        return true;
    }
};