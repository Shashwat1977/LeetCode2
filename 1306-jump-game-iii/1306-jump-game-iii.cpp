class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> visited(n);
       return dfs(start,visited,arr);
    }
    bool dfs(int start,vector<int>& visited,vector<int>& arr){
        if(start<0 || start>= arr.size() || visited[start] == 1){
            return false;
        }
        if(arr[start] == 0){
            return true;
        }
        visited[start] = 1;
        return dfs(start-arr[start],visited,arr) || dfs(start+arr[start],visited,arr);
    }
};