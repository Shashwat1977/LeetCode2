class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0;
        int h = letters.size()-1;
        while(l<=h){
            int m = l+(h-l)/2;
            if(letters[m] > target){
                h = m-1;
            }else{
                l = m+1;
            }
        }
        if(l == letters.size()){
            return letters[0];
        }else{
            return letters[l];
        }
    }
};