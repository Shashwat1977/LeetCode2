class Solution {
public:
    int getReverseInt(int value) {
    int resultNumber = 0;
    for (int i = value; i != 0;) {
        int d = i / 10;
        resultNumber = (resultNumber - d) * 10 + i;
        i = d;
    }
    return resultNumber;
}
    int countNicePairs(vector<int>& nums) {
        map<int,int> mp;
        for(int i = 0;i<nums.size();i++){
            int rev = getReverseInt(nums[i]);
            mp[nums[i]-rev]++;
        }
        long long cnt=0;
        for(auto it:mp){
            long long c = it.second;
            cnt+= c*(c-1)/2;
        }
        return cnt%(1000000007);
    }
};