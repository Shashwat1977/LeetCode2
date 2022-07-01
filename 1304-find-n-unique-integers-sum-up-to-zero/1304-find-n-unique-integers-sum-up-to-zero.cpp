class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> temp;
        bool flag = n%2==0?true:false;
        n/=2;
        for(int i = -n;i<=n;i++){
            if(i == 0) continue;
            temp.push_back(i);
        }
        if(flag) return temp;
        temp.push_back(0);
        return temp;
    }
};