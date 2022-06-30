class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int d = INT_MAX;
        for(int i = k;i<=nums.size();i++){
            d = min(d,nums[i-1]-nums[i-k]);
        }
        return d;
    }
};