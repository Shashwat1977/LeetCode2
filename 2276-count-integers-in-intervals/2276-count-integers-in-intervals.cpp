class CountIntervals {
public:
    int sum = 0;
    set<pair<int,int>> st;
    CountIntervals() {
        
    }
    
    void add(int left, int right) {
        if(st.empty()){
            st.insert({left,right});
            sum += right-left+1;
        }else{
            auto it = st.lower_bound({left,0});
            if(it != st.begin()) it--;
                    int newl = left, newr = right;

            vector<pair<int,int>> vec;
            while(it!=st.end()){
                auto p = *it;
                if(p.first>right) break;
                if(!(p.second<left || p.first>right)){
                    vec.push_back(p);
                    newl = min(newl,p.first);
                    newr = max(newr,p.second);
                }
                it++;
            }
            for(auto it:vec){
                sum -= (it.second-it.first+1);
                st.erase(it);
            }
            st.insert({newl,newr});
            sum += (newr-newl+1);
        }
    }
    
    int count() {
        return sum;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */