class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
int maxCapacity=0;
         int n=weights.size();
        
        for(int i=0;i<n;i++)
            maxCapacity+=weights[i];
        int h = maxCapacity;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(possible(mid,weights,days)){
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
    bool possible(int mx,vector<int> weights,int day){
        int currSum = 0;
        int days = 1;
        for(int i = 0;i<weights.size();i++){
            currSum+=weights[i];
            if(currSum>mx){
                currSum=weights[i];
                days+=1;
            }
        }
        if(days<=day){
            return true;
        }
        return false;
    }
};