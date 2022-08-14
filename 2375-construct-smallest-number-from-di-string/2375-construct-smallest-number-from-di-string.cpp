class Solution {
public:
    string smallestNumber(string pattern) {
        int i = 0;
        string res = "";
        stack<int> st;
        for(int i = 0;i<=pattern.size();i++){
            st.push(i+1);
            if(pattern[i] == 'I'){
                while(!st.empty()){
                    res += to_string(st.top());
                    st.pop();
                }
            }
        }
        while(!st.empty()){
                    res += to_string(st.top());
                    st.pop();
                }
        return res;
    }
};