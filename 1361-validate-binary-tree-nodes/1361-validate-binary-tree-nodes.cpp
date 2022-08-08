class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        list<int> adj[n];
        vector<int> indegree(n,0);
        for (int i=0;i<n;i++) {
            if(leftChild[i]!=-1){
                if(++indegree[leftChild[i]]>1){
                    return false;
                }
                adj[i].push_back(leftChild[i]);
            } 
            if(rightChild[i]!=-1){
                if(++indegree[rightChild[i]]>1){
                    return false;
                }
                adj[i].push_back(rightChild[i]);
            }
        }
        queue<int> q;
        int root=-1;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                if(root!=-1){
                    return false;
                }
                q.push(i); // DEGREE 0 means its the root
                root=i;
            }
        }        
        if(root==-1){
            return false;
        }
        int cnt=0;
        while(!q.empty()){  //DOING TOPOLOGY SORT
            int x=q.front();
            q.pop();
            cnt++;
            for(auto nei: adj[x]){
                indegree[nei]--; // we came to this nei from its source, so this nei node one preNode has been traversed and hence reduce its dependency
                if(indegree[nei]==0){  // we have traversed every node which was pointing on nei and now we can take it in queue for furthur processing
                    q.push(nei);
                }
            }
        }
        return cnt==n; // through topology we traversed cnt nodes and if it is equal to given n nodes return true
    }
};