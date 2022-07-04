class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> hash(1001);
        for(auto it:nums){
            for(int i = 0;i<it.size();i++){
                hash[it[i]] = hash[it[i]]+1;
            }
            }vector<int> temp;
        for(int i = 0;i<1001;i++){
            if(hash[i] == n) temp.push_back(i);
        }
        return temp;
    }
};