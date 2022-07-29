class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int cnt = 0;
        long long sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        long long  s = 0;
        for(int i = 0;i<nums.size()-1;i++){
            s +=nums[i];
            if(s>= sum-s){
                cnt++;
            }
        }
        return cnt;
    }
};