class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int mx = 0;
        if(points.size() == 1) return 1; 
        for(int i = 0;i<points.size();i++){
            map<pair<int,int>,int> mp;
            int dup = 0;
            for(int j = i+1;j<points.size();j++){
                int dy = points[j][1]-points[i][1];
                int dx = points[j][0] - points[i][0];
                if(dy == 0 && dx == 0) dup++;
                else{
                    int g = gcd(dy,dx);
                    mp[{dx/g,dy/g}]++;
                }
            }
            mx = max(mx,dup);
            for(auto it:mp){
                mx = max(mx,it.second+dup+1);
            }
        }
        return mx;
    }
    private:
    int gcd(int a, int b) {
        while (b) {
            a = a % b;
            swap(a, b);
        }
        return a;
    }
};