class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
            int n = prices.size();
            vector<int> ahead(2,0);
            vector<int> curr(2,0);
            for(int i = n-1;i>=0;i--){
                for(int buy = 0;buy<=1;buy++){
                    if(buy){
                        curr[buy] = max(-prices[i]+ahead[0],ahead[1]);
                    }else{
                        curr[buy] = max(prices[i]-fee+ahead[1],ahead[0]);
                    }
                }
                ahead = curr;
            }
        return ahead[1];
    }
};