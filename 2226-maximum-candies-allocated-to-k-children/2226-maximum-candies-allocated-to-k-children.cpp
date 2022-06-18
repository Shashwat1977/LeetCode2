class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1;
        int h = *max_element(candies.begin(),candies.end());
        while(l<=h){
            int mid = l+(h-l)/2;
            if(possible(candies,k,mid)){
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
        return h;
    }
    bool possible(vector<int>& candies,long long k,int mid){
        long long cnt = 0;
        for(auto it:candies){
            if(it>=mid) cnt+=it/mid;
        }
        return cnt>=k;
    }
};