class Solution {
public:
    static const int N = 1e5+2;
    int parent[N];
int rak[N];

void make(int v){
	parent[v] = v;
	rak[v] = 0;
}

int find(int v){
	if(v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}
void Union(int a,int b){
	a = find(a);
	b = find(b);
	if(a!=b){
		if(rak[a]<rak[b]){
			parent[a] = b;
		}else if(rak[b]<rak[a]){
			parent[b] = a;
		}else{
			parent[b] = a;
			rak[a]++;
		}
	}
}
    int longestConsecutive(vector<int>& num) {
        if(num.size() == 0) return 0;
         unordered_set<int> record(num.begin(),num.end());
        int res = 1;
        for(int n : num){
            if(record.find(n)==record.end()) continue;
            record.erase(n);
            int prev = n-1,next = n+1;
            while(record.find(prev)!=record.end()) record.erase(prev--);
            while(record.find(next)!=record.end()) record.erase(next++);
            res = max(res,next-prev-1);
        }
        return res;
    }
};