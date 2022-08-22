class Solution {
public:
    vector<int> ans;
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> vec;
        for(int i = 0;i<nums.size();i++){
            vec.push_back({nums[i],i});
        }
        ans.resize(nums.size(),0);
        helper(0,nums.size()-1,vec);
        return ans;
    }
    void helper(int l,int r,vector<pair<int,int>>& vec){
        if(l>=r) return;
        int m = l+(r-l)/2;
        helper(l,m,vec);
        helper(m+1,r,vec);
        merge(l,m,r,vec);
    }
    void merge(int l,int m,int r,vector<pair<int,int>>& vec){
        int k = 0;
        vector<pair<int,int>> temp(r-l+1);
        int i = l;
        int j = m+1;
        int cnt = 0;
        while(i<=m && j<=r){
            if(vec[i].first<=vec[j].first){
                ans[vec[i].second] += cnt;
                temp[k] = vec[i];
                i++;k++;
                
            }else{
                cnt++;
                temp[k] = vec[j];
                j++;
                k++;
            }
        }
        while(i<=m){
            ans[vec[i].second] += cnt;
            temp[k] = vec[i];
            i++;k++;
        }
        while(j<=r){
            temp[k] = vec[j];
            j++;k++;
        }
        i = l;
        k = 0;
        while(i<=r){
            vec[i] = temp[k];
            i++;
            k++;
        }
    }
};