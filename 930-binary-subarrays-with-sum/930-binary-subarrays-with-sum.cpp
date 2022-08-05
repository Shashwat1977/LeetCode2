class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
               unordered_map<int,int> mp;
        int sum = 0;
        mp[0] = 1;
        int ans = 0;
        for(auto it:nums){
            sum+= it;
            
            int rem = sum - goal;
            if(mp.find(rem)!=mp.end()){
                ans+=mp[rem];
            }
            mp[sum]++;
        }
        return ans;
    }
};