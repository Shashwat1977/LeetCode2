class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int j = 0;int i = 0;
        if(k == 0) return 0;
        long long pro = 1;
        int ans = 0;
        while(j<nums.size()){
            pro = pro*nums[j];
            while(pro>=k){
                pro /= nums[i];
                i++;
            }
            if(i<= j)
                ans+= (j-i+1);
            j++;
        }
        return ans;
    }
};