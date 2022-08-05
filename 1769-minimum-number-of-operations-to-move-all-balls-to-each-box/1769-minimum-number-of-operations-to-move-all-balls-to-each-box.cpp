class Solution {
public:
    vector<int> minOperations(string boxes) {
vector<int>pre;
        vector<int>suf;
        vector<int>ans;
        int p=0; // this variable track how many balls in previous box
        for(int i=0;i<boxes.length();i++) 
        {
            if(i==0)// at the 0th index left side there is no box so put 0
            {
                pre.push_back(0);
                p+=boxes[i]-'0';
                continue;
            }
            pre.push_back(p+pre.back()); // here you need add previous box ball + previous move
            p+=boxes[i]-'0';
        }
		
		//suffix sum is same prefix sum;
        p=0;
        for(int i=boxes.length()-1;i>=0;i--)
        {
            if(i==boxes.length()-1)
            {
                suf.push_back(0);
                p+=boxes[i]-'0';
                continue;
            }
            suf.push_back(p+suf.back());
            p+=boxes[i]-'0';
            
        }
        int n=suf.size();
        for(int i=0;i<pre.size();i++)
        {
            ans.push_back(pre[i]+suf[n-i-1]);
        }
        return ans;

    }
};