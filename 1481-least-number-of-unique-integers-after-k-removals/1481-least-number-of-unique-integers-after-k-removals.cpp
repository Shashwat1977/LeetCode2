class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
    unordered_map<int,int> mp;
    
    for(auto e:arr)
    {
        mp[e]++;
    }
    
    for(auto e:mp)
    {
        pq.push({e.second,e.first});
    }
    
    while(k and pq.size())
    {
        auto x=pq.top();
        pq.pop();
        int res=min(x.first,k);
        x.first-=res;
        k-=res;
        if(x.first)
            pq.push(x);
    }
    return pq.size();
}
};