class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int cnt = 0;
        long long sum = accumulate(nums.begin(),nums.end(),(long long)0);
        long long  s = 0;
        for(int i = 0;i<nums.size()-1;i++){
            s = s+ (long long)nums[i];
            if(s>= sum-s){
                cnt++;
            }
        }
        return cnt;
    }
};