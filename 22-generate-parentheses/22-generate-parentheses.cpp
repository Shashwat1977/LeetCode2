class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n== 0){
            return ans;
        }
        gen(ans,0,"",n);
        return ans;
    }
    void gen(vector<string>& ans,int count,string temp,int len){
        if(count<0) return ;
        if(temp.size()>2*len){
            return;
        }
        if(temp.size() == 2*len && count == 0){
            ans.push_back(temp);
        }
        
        gen(ans,count+1,temp+'(',len);
        gen(ans,count-1,temp+')',len);
    }
};