class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> prefix(n+2,0);
        for(int i = 0;i<bookings.size();i++){
            int s = bookings[i][0];
            int e = bookings[i][1];
            int val = bookings[i][2];
            prefix[s]+=val;
            prefix[e+1] -= val;
        }
        vector<int> ans;
        for(int i = 1;i<=n;i++){
            prefix[i] += prefix[i-1];
            ans.push_back(prefix[i]);
        }
        return ans;
    }
};