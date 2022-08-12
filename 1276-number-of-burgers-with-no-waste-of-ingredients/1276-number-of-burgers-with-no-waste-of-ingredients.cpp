class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(tomatoSlices%2 != 0) // if tomatoSlices are odd, tomato ingredient will be wasted for sure since both type of burgers use even number of tomato slices
            return {};
        
        int m, n;
        
        //4m + 2n = tomatoSlices;
        //m + n = cheeseSlices;
        
        m = (tomatoSlices-2*cheeseSlices)/2;
        n = (4*cheeseSlices-tomatoSlices)/2;
        
        if(m < 0 || n < 0)
            return {};
        
        vector<int> ans;
        ans.push_back(m);
        ans.push_back(n);
        return ans;
    }
};