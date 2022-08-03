class MyCalendar {
public:
    set<pair<int, int>> st;
    MyCalendar() {
        
    }
    
    
    bool book(int start, int end) {
        auto it = st.lower_bound({start, end}); //Find a start which is >= curr.start

        if(it != st.end() && end > it->first)
            return false;
        if(it != st.begin() && start < ((--it)->second))
            return false;
        
        st.insert({start, end});
        return true;
    }
};