class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int,long long> mp;
        long long total = 0;
        for(auto it:tasks){
            total++;
            if(mp.count(it) && total-mp[it]<=space){
                total += space-(total-mp[it])+1;
            }
            mp[it] = total;
        }
        return total;
    }
};