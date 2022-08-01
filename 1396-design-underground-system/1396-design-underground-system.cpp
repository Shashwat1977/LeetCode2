class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> mp;
    map<string,pair<int,int>> mpp;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id] = {stationName,t};
    }
    
    void checkOut(int id, string end, int t) {
        int time = mp[id].second;
        string start = mp[id].first;
        start= start+">"+end;
        pair<int,int> pt = mpp[start];
        int totat = pt.first + (t-time);
        int curr = pt.second + 1;
        mpp[start] = {totat,curr};
    }
    
    double getAverageTime(string s, string e) {
        string t = s+">"+e;
        return (1.0*mpp[t].first)/mpp[t].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */