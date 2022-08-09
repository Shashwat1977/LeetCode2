class Solution {
public:
    int reductionOperations(vector<int>& nums) {
       int mn = *min_element(nums.begin(),nums.end());
        map<int,int> mp;
        for(auto it:nums)
        {
            if(it==mn)continue;
            mp[it]++;
        }
        int ans = 0;
        int cnt = mp.size();
        for(auto it=mp.rbegin();it!=mp.rend();it++)
        {
            ans += it->second*cnt;
            cnt--;
        }
        return ans;
    }
};