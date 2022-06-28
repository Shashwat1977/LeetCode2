class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(int i = 0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        auto it = s.end();
        it--;
        if(s.size()<3){
            return *(it);
        }else{
            it--;
            it--;
            return *(it);
        }
    }
};