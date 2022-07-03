class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>vec;
        vector<int>vec1;
        vector<int>vec2;
        int hsh1[3000]={0};
        int hsh2[3000]={0};
        for(int i=0;i<nums1.size();i++)
            hsh1[nums1[i]+1000]=1;
        for(int i=0;i<nums2.size();i++)
            hsh2[nums2[i]+1000]=1;
        for(int i=0;i<3000;i++)
        {
            if(hsh1[i] &&!hsh2[i])
                vec1.push_back(i-1000);
            if(hsh2[i] && !hsh1[i])
                vec2.push_back(i-1000);
        }
        vec.push_back(vec1);
        vec.push_back(vec2);
        return vec;

    }
};