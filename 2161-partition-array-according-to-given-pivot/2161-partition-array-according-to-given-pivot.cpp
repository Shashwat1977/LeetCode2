class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less;
        vector<int> eq;
        vector<int> great;
        for(auto it:nums){
            if(it<pivot) less.push_back(it);
            if(it == pivot) eq.push_back(it);
            if(it>pivot) great.push_back(it);
        }
        vector<int> ans;
        for(auto it:less) ans.push_back(it);
        for(auto it:eq) ans.push_back(it);
        for(auto it:great) ans.push_back(it);
        return ans;
    }
};