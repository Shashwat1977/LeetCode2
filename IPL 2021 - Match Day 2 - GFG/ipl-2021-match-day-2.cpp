// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> nums, int n, int k) {
        deque<int> q;
        vector<int> temp;
        int i = 0;
        int j = 0;
        while(j<nums.size()){
            while(!q.empty() && q.back()<nums[j]){
                q.pop_back();
            }q.push_back(nums[j]);
            if(j-i+1 < k){
                j++;
            }else if(j-i+1 == k){
                temp.push_back(q.front());
                if(q.front() == nums[i]){
                    q.pop_front();
                }
                i++;
                j++;
            }
        }
        return temp;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends