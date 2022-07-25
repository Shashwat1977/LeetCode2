class Solution {
public:
    int minimumSum(int n) {
        vector<int> vec;
        while(n){
            vec.push_back(n%10);
            n/=10;
        }
        sort(vec.begin(),vec.end());
        return 10*vec[0]+vec[3] + 10*vec[1]+vec[2];
    }
};