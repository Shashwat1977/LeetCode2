class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        if(n == 0)return res;
        vector<int> temp;
        recur(res,temp,nums,0);
        return res;
    }
    void recur(vector<vector<int>>& res,vector<int>& temp,vector<int>& nums,int i){
        if(i == nums.size()){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        recur(res,temp,nums,i+1);
        temp.pop_back();
        recur(res,temp,nums,i+1);
    }
};