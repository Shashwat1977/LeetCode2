class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.rbegin(),s.rend());
        int sum = 0;
        int curr = 0;
        int mx = 0;
        for(auto it:s){
            sum += it;
            curr += sum;
            mx = max(mx,curr);
        }
        return mx;
    }
};