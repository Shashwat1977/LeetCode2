class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> m ; 
        m[2] = "abc"; 
    m[3] = "def"; 
    m[4] = "ghi"; 
    m[5] = "jkl"; 
    m[6] = "mno"; 
    m[7] = "pqrs";
    m[8] = "tuv"; 
    m[9] = "wxyz";
        
        vector<string> ans;
        if(digits == "") return ans;
    helper(0,digits,"",m,ans);
        return ans;
    }
    void helper(int ind,string d,string temp,unordered_map<int,string>& m,vector<string>& ans){
        if(ind == d.size()){
            ans.push_back(temp);
            return;
        }
        string res = m[d[ind]-'0'];
        for(int i = 0;i<res.size();i++){
            temp+=res[i];
            helper(ind+1,d,temp,m,ans);
            temp.pop_back();
        }
    }
};