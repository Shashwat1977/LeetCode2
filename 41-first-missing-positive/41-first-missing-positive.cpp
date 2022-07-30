class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       unordered_set<int>s;
         int res=1;
        
         for(int i=0;i<nums.size();i++){
             if(nums[i]>0){
                 s.insert(nums[i]);
             }
         }
         while(s.find(res)!=s.end()){
           res++;
        }
        return res;
    }
};