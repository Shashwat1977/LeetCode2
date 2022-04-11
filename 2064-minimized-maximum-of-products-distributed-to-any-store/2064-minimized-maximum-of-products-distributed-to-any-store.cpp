class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1;
        int h = *max_element(quantities.begin(),quantities.end());
        while(l<=h){
            int mid = l+(h-l)/2;
            if(possible(mid,quantities,n)){
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
    bool possible(int mid,vector<int>& quantities,int k){
        int count = 0;
        for(auto it:quantities){
            count+= ceil(it/(mid*1.0));
        }
        if(count<= k) return true;
        return false;
    }
};