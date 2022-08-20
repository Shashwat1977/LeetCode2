class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        int n = nums.size();
        int l = n/k;
         if(n % k != 0)
        {
            return false;
        }
        map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(int i=1;i<=l;i++){
            auto it = mp.begin();
            int temp = it->first;
            for(int j = temp;j<temp+k;j++){
                if(mp.find(j) == mp.end()) return false;
                mp[j] -- ;
                if(mp[j] == 0) mp.erase(j);
                
            }
        }
        return true;
    }
};