class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int a) {
        vector<int> dif;
        for(int i = 0;i<capacity.size();i++){
            dif.push_back(capacity[i]-rocks[i]);
        }
        sort(dif.begin(),dif.end());
        int i = 0;
        int cnt = 0;
        while(a>0 && i<dif.size()){
            if(a-dif[i]>=0){
                a-=dif[i];
                cnt++;
                i++;
            }else{
                break;
            }
        }
        return cnt;
    }
};