class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]] = i;
        }
        for(auto it:operations){
            int ind = mp[it[0]];
            nums[ind] = it[1];
            mp.erase(it[0]);
            mp[it[1]] = ind;
        }
        return nums;
    }
};