class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();
        int mx = arr[0];
        int long sum = 0;
        for(int i = 0;i<n;i++){
            sum+= arr[i];
            if(sum>mx){
                mx = sum;
            }
            sum = sum<0?0:sum;
        }
        return mx;
    }
};