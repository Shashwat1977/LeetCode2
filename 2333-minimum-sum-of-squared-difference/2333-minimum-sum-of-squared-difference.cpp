class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        map<int,int> mp;
        for(int i = 0;i<nums1.size();i++){
            mp[abs(nums1[i]-nums2[i])]++;
        }
        int k = k1+k2;
        while(k>0 && !mp.empty()){
            auto it = *--mp.end();
            if(it.first ==0 ) break;
            int val = it.second;
            if(val>=k){
                mp[it.first] -= k;
                mp[it.first-1] += k;
                k = 0;
            }else{
                mp[it.first-1] += val;
                mp.erase(it.first);
                k -= val;
            }
        }
        long long ans = 0;
        long long one = 1;
        for(auto it:mp){
            ans += (one)*it.first*it.first*it.second;
        }
        return ans;
    }
};