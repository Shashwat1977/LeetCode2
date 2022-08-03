class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        set<string> word;
        for(auto it:wordList){
            word.insert(it);
        }
        st.insert(beginWord);
        queue<string> q;
        q.push(beginWord);
        int res = 0;
        while(!q.empty()){
            int n = q.size();
            res++;
            for(int i = 0;i<n;i++){
                string d = q.front();
                
                if(d == endWord) return res;
                q.pop();
                for(int j = 0;j<d.size();j++){
                    string t = d;
                    for(char f='a';f<='z';f++){
                        t[j] =f;
                        if(word.count(t) && !st.count(t)){
                            q.push(t);
                            st.insert(t);
                        }
                    }
                }
            }
        }
        return 0;
    }
};