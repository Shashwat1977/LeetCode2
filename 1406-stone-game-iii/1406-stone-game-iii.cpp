class Solution {
public:
   vector<int> dp;

int fun(int idx, vector<int>& arr){
    if(idx >= arr.size())
        return 0;
    if(dp[idx] != -1)
        return dp[idx];
    
    
    int ans = INT_MIN, sf = 0;
    
    for(int di = 0; di < 3; di++){
        int i = idx + di;
        if(i < arr.size()){
            sf += arr[i];
            ans = max(ans, sf - fun(i+1,arr));
        }
    }
    
    return dp[idx] = ans;
}

string stoneGameIII(vector<int>& arr) {
    
    dp = vector<int>(arr.size(),-1);
    
    int diff = fun(0,arr);
    
    if(diff == 0)
        return "Tie";
    else if(diff > 0)
        return "Alice";
    else 
        return "Bob";
    
}
};

