class Bitset {
    vector<bool> bits;
    bool bflip;
    int onecount;
    void _fix(int idx)
    {
        if (bits[idx]==0)
            onecount++;
        bits[idx] = true;
    }
    
    void _unfix(int idx) {
        if (bits[idx] == 1)
            onecount--;
        bits[idx] = false;
    }
public:
    Bitset(int size) {
        bits.resize(size,false);
        bflip = false;
        onecount = 0;
    }
    
    void fix(int idx) {
        if (bflip) _unfix(idx);
        else _fix(idx);
    }
    
    void unfix(int idx) {
        if (bflip) _fix(idx);
        else _unfix(idx);
    }
    
    void flip() {
        bflip = !bflip;
    }
    
    bool all() {
        return count() == bits.size();
    }
    
    bool one() {
        return count() >= 1;
    }
    
    int count() {
        if (!bflip) return onecount;
        else return bits.size() - onecount;
    }
    
    string toString() {
        string ans;
        for(int i=0; i<bits.size(); i++)
        {
            if (bits[i])
                ans.push_back(bflip?'0':'1');
            else
                ans.push_back(bflip?'1':'0');
        }
        return ans;
    }
};