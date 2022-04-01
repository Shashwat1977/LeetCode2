class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1;
        int h = arr.size()-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(arr[mid-1]<arr[mid]) l = mid+1;
            else h = mid-1;
        }
        return h;
    }
};