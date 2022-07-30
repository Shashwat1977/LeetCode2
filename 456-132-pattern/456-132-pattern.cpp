class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0);
        int mn = nums[0];
        prefix[0] = nums[0];
        for(int i = 0;i<n-1;i++){
           mn = min(mn,nums[i]);
           prefix[i+1] = mn;
        }
        vector<int> ngr;
        stack<int> st;
        for(int i = 0;i<n;i++){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(st.empty()) ngr.push_back(-1);
            else ngr.push_back(st.top());
            st.push(i);
        }
        for(int i = n-1;i>=2;i--){
            if(ngr[i] != -1 && nums[i] > prefix[ngr[i]])
                return true;
        }
        return false;
    }
};