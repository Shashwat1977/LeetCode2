class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
sort(points.begin(), points.end());
        int ans = 1;
        
        int e = points[0][1];
        
        for(int i=1; i<points.size(); i++){
            if(points[i][0]<=e){
                e = min(e, points[i][1]);
            }    
            else{
                ans++;
                e = points[i][1];
            }
        }        
        return ans;
    }
};