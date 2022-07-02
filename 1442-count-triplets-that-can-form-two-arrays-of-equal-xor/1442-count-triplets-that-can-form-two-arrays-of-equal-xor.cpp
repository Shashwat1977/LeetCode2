class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int cnt = 0;
        for(int i = 0;i<arr.size();i++){
            int xo = arr[i];
            for(int j = i+1;j<arr.size();j++){
                xo^=arr[j];
                if(xo == 0){
                    cnt += (j-i);
                }
            }
        }
        return cnt;
    }
};