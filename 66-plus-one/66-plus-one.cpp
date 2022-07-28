class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int carry= 0;
        int i = 0;
        while(1 && i<digits.size()){
            if(digits[i] != 9){
                digits[i] +=1;
                carry = 0;
                reverse(digits.begin(),digits.end());
                return digits;
            }else{
                digits[i] = 0;
                i++;
                carry = 1;
            }
        }
        if(carry){
            digits.push_back(1);
            
        }
        reverse(digits.begin(),digits.end());
            return digits;
    }
};