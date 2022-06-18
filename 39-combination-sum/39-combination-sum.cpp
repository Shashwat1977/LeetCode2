class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        recur(res,temp,target,c,c.size()-1);
        return res;
    }
    void recur(vector<vector<int>>& res,vector<int>& temp,int target,vector<int>& c,int i){
        if(target == 0){
            res.push_back(temp);
            return;
        }
        if(i == -1) return;
        if(c[i]<=target){
            temp.push_back(c[i]);
            recur(res,temp,target-c[i],c,i);
            temp.pop_back();
        }
        recur(res,temp,target,c,i-1);
    }
};