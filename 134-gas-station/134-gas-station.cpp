class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       vector<int> dif(gas.size());
        int n = gas.size();
        long long sum = 0;
        for(int i = 0;i<n;i++){
            dif[i] = gas[i]-cost[i];
            sum+=dif[i];
        }
        if(sum<0) return -1;
        int mx = sum;
        long long ls = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            ls += dif[i];
            sum -= dif[i];
            if(sum>mx){
                ans = i+1;
                mx = sum;
            }
        }
        return ans;
    }
};