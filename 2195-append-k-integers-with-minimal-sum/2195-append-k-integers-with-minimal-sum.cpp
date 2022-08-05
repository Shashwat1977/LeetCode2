class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        set<int> s(nums.begin(),nums.end());
        long long sum = 0;
        long long k2 = k;
        for(auto it:s){
            auto val = it;
            if(it<=k2){
                sum += it;
                k2++;
            }else{
                break;
            }
        }
        return (long long)(k2*(k2+1)/2) - sum;
    }
};