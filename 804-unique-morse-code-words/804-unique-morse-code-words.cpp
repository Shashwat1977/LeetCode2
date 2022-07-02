class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s;
        string temp[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(auto it:words){
            string dum = "";
            for(int i = 0;i<it.size();i++){
                dum += temp[it[i]-'a'];
            }
            s.insert(dum);
        }
        return s.size();
    }
};