// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        priority_queue<pair<int,int>> pq;
        for(int i = 0;i<n;i++){
            if(abs(arr[i]-x) == 0) continue;
            pq.push({abs(arr[i]-x),-1*arr[i]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> temp;
        while(pq.size()>0){
            temp.push_back(-1*pq.top().second);
            pq.pop();
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends