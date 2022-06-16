class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        
        int mx = 0;
        for(auto it:nums){
            mx = mx|it;
        }
        int n = nums.size();
        int cnt = 0;
        int a = 0;
        
        vector<int> temp;
        for(int i = 1;i<(1<<n);i++){
            cnt = 0;
            for(int j = 0;j<n;j++){
                if(i&(1<<j)){
                    cnt = cnt|nums[j];
                }
            }
            if(cnt == mx){
                a++;
            }
 
        }
        return a;
    }
};