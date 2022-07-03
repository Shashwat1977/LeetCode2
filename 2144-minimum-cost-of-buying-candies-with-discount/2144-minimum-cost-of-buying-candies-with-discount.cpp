class Solution {
public:
    int minimumCost(vector<int>& vec) {
        int sum = 0;
        sort(vec.rbegin(),vec.rend());
        for(int i = 0;i<vec.size();i++){
            if((i+1)%3==0) continue;
            else sum+=vec[i];
        }
        return sum;
    }
};