class Solution {
public:
    int countElements(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        int mn = *min_element(nums.begin(),nums.end());
        int cnt = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]>mn && nums[i]<mx) cnt++;
        }
        return cnt;
    }
};