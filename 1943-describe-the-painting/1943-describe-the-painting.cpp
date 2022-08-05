class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& seg) {
        vector<vector<long long>> v;
        map<long long,long long> m;
        long long int i=0;
        while(i<seg.size())
        {
            m[seg[i][0]]+=seg[i][2];
            m[seg[i][1]]-=seg[i][2];
            i++;
        }
        long long int j=0,k=0;
        for(auto x:m)
        {
            long long int prev=j;
            j+=x.second;
            if(prev>0)
                v.push_back({k,x.first,prev});
            k=x.first;
        }
        return v;

    }
};