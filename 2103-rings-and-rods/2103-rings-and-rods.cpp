class Solution {
public:
    int countPoints(string rings) {
        vector<vector<int>> rods(10,vector<int>(3,0));
        for(int i = 0;i<rings.size();i+=2){
            if(rings[i]=='R'){
                rods[rings[i+1] - '0'][0] = 1;
            }
            else if(rings[i]=='G'){
                rods[rings[i+1] - '0'][1] = 1;
            }
            else{
                rods[rings[i+1] - '0'][2] = 1;
            }
        }
        int ans = 0;
        for(auto n:rods){
            int count = 0;
            for(auto i:n){
                if(i==1){
                    count += 1;
                }
            }
            if(count==3){
                ans+=1;
            }
        }
        return ans;
    }
};