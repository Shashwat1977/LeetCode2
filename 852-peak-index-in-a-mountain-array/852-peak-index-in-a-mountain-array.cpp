class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1;
        int h = arr.size()-1;
        while(l<=h){
            int m = l+(h-l)/2;
            if(arr[m-1]<arr[m]){
                l = m+1;
            }else{
                h = m-1;
            }
        }
        return h;
    }
};