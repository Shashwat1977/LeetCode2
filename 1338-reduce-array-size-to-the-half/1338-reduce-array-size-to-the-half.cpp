class Solution {
public:
    int minSetSize(vector<int>& arr) {
std::unordered_map<int,int>map;
        std::priority_queue<int>pq;
        int result =0;
        int count = (int)arr.size();
        for(int i=0;i<(int)arr.size();i++)
            map[arr[i]]++;
        for(auto it =map.begin();it!=map.end();it++)
            pq.push(it->second);
        while(count>(int)arr.size()/2){
            count -= pq.top();
            pq.pop();
            result++;
        }
        return result;
    }
};