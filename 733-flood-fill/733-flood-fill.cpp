class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row = image.size()-1;
        int col = image[0].size()-1;
        int source = image[sr][sc];
        recur(image,sr,sc,newColor,row,col,source);
        return image;
    }
    void recur(vector<vector<int>>& image,int i,int j,int C,int row,int col,int s){
        if(i>row || i<0 || j<0 || j>col || image[i][j]!=s)
            return;
        if(image[i][j] == C) return;
        image[i][j] = C;
        recur(image,i+1,j,C,row,col,s);
        recur(image,i,j-1,C,row,col,s);
        recur(image,i-1,j,C,row,col,s);
        recur(image,i,j+1,C,row,col,s);
    }
};