class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i = 0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int top = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            if(top == second) continue;
            pq.push(top-second);
        }
        if(pq.size() != 0) return pq.top();
        else return 0;
    }
};