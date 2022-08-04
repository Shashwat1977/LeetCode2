class MyCalendarThree {
public:
    map<int,int> mp;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        int count = 0;
        int mx = INT_MIN;
        mp[start]++;
        mp[end]--;
        for(auto it:mp){
            count+=it.second;
            mx = max(mx,count);
        }
        return mx;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */