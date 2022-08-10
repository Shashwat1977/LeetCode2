class Solution {
public:
    int maxScore(vector<int>& points, int k) {
        long long sum = accumulate(points.begin(),points.end(),(long long)0);
        int n = points.size();
        int size = n-k;
        int i = 0;int j = 0;
        long long temp = 0;
        int ans=INT_MAX;
        while(j<n){
            temp += points[j];
            if(j-i+1 == size){
                ans = min(ans,(int)temp);
            }
            if(j-i+1>size){
                temp -= points[i];
                i++;
                ans = min(ans,(int)temp);
            }
            j++;
        }
        return sum-ans;
    }
};