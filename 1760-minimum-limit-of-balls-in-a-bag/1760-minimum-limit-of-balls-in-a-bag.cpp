class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size()-1;
        int l = 1;
        int h = 1e9;
        while(l<=h){
            int m = l+(h-l)/2;
            if(feasible(m,nums,maxOperations)){
                h = m-1;
            }else{
                l = m+1;
            }
        }
        return l;
    }
    bool feasible(int m,vector<int>& nums,int mx){
        int cnt = 0;
        for(auto it:nums){
            cnt += it/m;
            if(it%m == 0) cnt--;
        }
        return cnt<=mx;
    }
};