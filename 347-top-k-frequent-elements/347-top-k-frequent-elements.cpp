class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.size() == 0) return res;
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto it: mp){
            pq.push({it.second,it.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(pq.size()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};