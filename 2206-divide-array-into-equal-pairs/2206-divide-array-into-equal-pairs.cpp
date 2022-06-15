class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        int cnt =0 ;
        for(auto it:mp){
            if(it.second&1 != 0) {
                return false;
            }cnt+= it.second/2;
        }
        return cnt == nums.size()/2;
    }
};