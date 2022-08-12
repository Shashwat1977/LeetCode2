class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int even = 0;
        int odd = 0;
        for(int i = n-1; i >= 0; i--){
            if(i&1){
                odd += nums[i];
            }
            else{
                even += nums[i];
            }
        }
        int Even = 0;
        int Odd = 0;
        int cnt = 0;
        for(int i = n-1; i >= 0; i--){
            if(i&1){
                odd -= nums[i];
                if(odd+Even == even+Odd) cnt++;
                Odd += nums[i];
            }
            else{
                even -= nums[i];
                if(even+Odd == odd+Even) cnt++;
                Even += nums[i];
            }
        }
        return cnt;
    }
};
