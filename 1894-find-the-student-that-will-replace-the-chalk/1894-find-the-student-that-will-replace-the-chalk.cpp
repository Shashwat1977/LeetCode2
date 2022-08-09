class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = accumulate(chalk.begin(),chalk.end(),(long long)0);
        if(sum<=k){
            k%=sum;
        }
        long long val = 0;
        for(int i = 0;i<chalk.size();i++){
            if(chalk[i]>k){
                return i;
            }
            k-=chalk[i];
        }
        return 0;
    }
};