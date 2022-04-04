class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l =1 ;
        int h = m*n;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(possible(m,n,k,mid)){
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
    bool possible(int m,int n,int k,int mid){
        int count = 0;
        for(int i = 1;i<=m;i++){
            count+=min(n,mid/i);
        }
        if(count>=k) return true;
        return false;
    }
};