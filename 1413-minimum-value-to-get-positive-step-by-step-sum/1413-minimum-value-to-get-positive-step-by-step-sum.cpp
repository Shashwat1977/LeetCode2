class Solution {
public:
    int minStartValue(vector<int>& nums) {
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        for(int i = 1;i<nums.size();i++){
            prefix[i] = prefix[i-1]+nums[i];
        }
        int min = *min_element(prefix.begin(),prefix.end());
        if(min-1>=0) return 1;
        return abs(min-1);
    }
};