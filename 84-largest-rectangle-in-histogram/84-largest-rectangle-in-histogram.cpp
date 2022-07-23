class Solution {
public:
    
    vector<int> nsl(vector<int> &heights){
        stack<pair<int,int>> st;
        vector<int> v;
        
        for(int i=0;i<heights.size();i++){
            while(!st.empty() and st.top().first>=heights[i]){
                st.pop();
            }
            
            st.empty() ? v.push_back(-1) : v.push_back(st.top().second);
            
            st.push({heights[i],i});
        }
        
        return v;
    }

    vector<int> nsr(vector<int> &heights){
        stack<pair<int,int>> st;
        vector<int> v;
        
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() and st.top().first>=heights[i]){
                st.pop();
            }
            
            st.empty() ? v.push_back(heights.size()) : v.push_back(st.top().second);
            
            st.push({heights[i],i});
        }
        
        reverse(v.begin(),v.end());
        return v;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> left=nsl(heights);
        vector<int> right=nsr(heights);
        
        int ans=0;
        
        for(int i=0;i<heights.size();i++){
            int width=right[i]-left[i]-1;
            ans=max(ans,heights[i]*width);
        }
        
        return ans;
    }
};