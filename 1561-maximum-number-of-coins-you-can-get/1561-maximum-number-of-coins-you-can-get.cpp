class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size()/3;
        sort(piles.begin(),piles.end());
        int cnt = 0;
        long long sum = 0;
        for(int i = piles.size()-2;i>=0;i-=2){
            sum += piles[i];
            cnt++;
            if(cnt == n) break;
        }
        return sum;
    }
};