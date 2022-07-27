class Solution {
public:
    long long numberOfWeeks(vector<int>& miles) {
        int n=miles.size();
        //so that the biggest element is at the end
        sort(miles.begin(),miles.begin()+n);
        
        long long prefix=0;
        
        for(int i=0;i<n-1;i++){   
            prefix+=miles[i];
        }
        
        prefix+=miles[n-1]>prefix?prefix+1:miles[n-1];
        
        return prefix;

    }
};