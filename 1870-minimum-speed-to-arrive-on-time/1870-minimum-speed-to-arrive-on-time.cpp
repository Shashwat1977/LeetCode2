class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1;
        int h = 1e9;
        bool con = false;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(possible(mid,dist,hour)){
                con = true;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        if(con == false) return -1;
        return l;
    }
    bool possible(int mid,vector<int>& dist,double hour){
        double time = 0.0;
        for(int i =0;i<dist.size();i++){
            if(i!= dist.size()-1){
                time+= ceil(dist[i]/(mid*1.0));
        }
            else{
                time+= dist[i]/(mid*1.0);
            }                    
    }
                            if(time<=hour) return true;
                            return false;
                            }
};