class Solution {
public:
    static bool compare(const vector<int> &v1,const vector<int> &v2){
        return v1[1]>v2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort( boxTypes.begin() , boxTypes.end() , compare) ;
        int ans = 0;
        for(int i = 0; i < boxTypes.size() ;i++){
            if(truckSize <= 0) break;
            int w = min(boxTypes[i][0] , truckSize);
            truckSize -= boxTypes[i][0];
            ans += w*boxTypes[i][1];
        }
        return ans;
    }
};