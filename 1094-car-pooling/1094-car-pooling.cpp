class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> prefix(1002,0);
        for(int i = 0;i<trips.size();i++){
            int s = trips[i][1]; int e = trips[i][2];
            int val = trips[i][0];
            prefix[s] += val;
            prefix[e] -=val;
        }
        for(int i = 0;i<=1001;i++){
            if(i == 0){
                if(prefix[0]>capacity) return false;
                continue;
            }
            prefix[i] += prefix[i-1];
            if(prefix[i]>capacity) return false;
        }
        return true;
    }
};