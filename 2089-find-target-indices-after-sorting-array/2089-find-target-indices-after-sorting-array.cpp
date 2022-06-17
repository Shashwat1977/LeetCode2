class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size()-1;
        int l = 0;
        int h = n;
        vector<int> temp;
        while(l<=h){
            int m = l+(h-l)/2;
            if(nums[m] == target){
                temp.push_back(m);
                int var = m-1;
                int var2 = m+1;
                for(int i = var;i>=0;i--){
                    if(nums[i]== target){
                        temp.push_back(i);
                    }else{
                        break;
                    }
              }
                for(int i = var2;i<=n;i++){
                    if(nums[i] == target){
                        temp.push_back(i);
                    }else{
                        break;
                    }
              }
                break;
            }
            else if(nums[m]>target){
                h = m-1;
            }else{
                l = m+1;
            }
        }
        sort(temp.begin(),temp.end());
        return temp;
    }
};