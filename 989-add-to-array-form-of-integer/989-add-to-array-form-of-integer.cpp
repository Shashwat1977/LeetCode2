class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = 0;
        int n = num.size();
        for(int i = n-1;i>=0;i--){
            int val = k%10;
            k/=10;
            if(num[i]+val +carry<= 9){
                num[i] += val+carry;
                carry = 0;
            }else{
                num[i] = (num[i]+val+carry)%10;
                carry = 1;
            }
        }
        
        while(k > 0) {
            int val = k%10;
            num.insert(num.begin(), (carry+val) % 10); 
            carry = (carry+val)/10;
            k /= 10;
        }
        if(carry){
            num.insert(num.begin(),carry);
        }
        
        return num;
    }
};