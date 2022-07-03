class Solution {
public:
    int largestInteger(int num) {
        
        
        string s= to_string(num);
        
        
        priority_queue<char> pqo,pqe;
        for(auto &i: s){
            if((i-'0')%2==0){
                pqe.push(i);
            }
            else{
                pqo.push(i);
            }
        }
        for(int j=0;j<s.size();j++){
            if((s[j]-'0')%2==0){
               s[j]= pqe.top();
                pqe.pop();
            }
            else{
                s[j]= pqo.top();
                pqo.pop();
            }
        }
        
        return stoi(s);
    }
};