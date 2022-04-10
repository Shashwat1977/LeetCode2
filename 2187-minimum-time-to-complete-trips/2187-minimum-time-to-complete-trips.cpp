class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1;
        long long h = *min_element(time.begin(),time.end())*(long long)totalTrips;
        while(l<=h){
            long long mid = l+(h-l)/2;
            if(possible(mid,time,totalTrips)){
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
    bool possible(long long mid,vector<int>& time,int k){
        long long total = 0;
        for(int i = 0;i<time.size();i++){
            total += mid/time[i];
        }
        if(total>=k) return true;
        return false;
    }
};