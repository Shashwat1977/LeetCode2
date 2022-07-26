class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), comp);
        int ans = 0, n = properties.size();
        int mx = properties[n-1][1];
        for(int i = n-1; i>0; i--) {
            mx = max(mx, properties[i][1]);
            if(mx > properties[i-1][1]) ans++;
        }
        return ans;
    }
    
private:
    static bool comp(vector<int> &a, vector<int> &b) {
        if(a[0] != b[0]) return b[0] > a[0];
        else return b[1] < a[1];
    }
};
