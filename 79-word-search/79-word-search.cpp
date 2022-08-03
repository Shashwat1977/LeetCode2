class Solution {
public:
   bool dfs(vector<vector<char>>& board , int i , int j , string word , int index ){
        
        // BASE CASE ( if we are able to find all char in a word)
        if(index == word.size()){
            return true;
        }
        
        // out of bound cases or if char does not match 
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index]){
            return false;
        }
        
        // if till here it does not return false meaning char is right and we can move ahead
        // before that i need to make sure that in this current path which I am exploring 
        // i should mark this as visited
        
        char c = board[i][j];
        board[i][j] = '*';
        
        // I need to explore all possible direction
        
        // remember I can explore all four direction but result will be true even if 1 path can
        // return me a true hence , we will use ||
        
        bool res =  dfs(board , i+1 , j , word , index+1) ||
        dfs(board , i , j+1, word , index+1) ||
        dfs(board , i-1 , j , word , index+1) ||
        dfs(board , i , j-1 , word , index+1);
        
        board[i][j] = c;
        
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int row = board.size();
        int col = board[0].size();
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                
                if(board[i][j] == word[0]){
                    
                    if(dfs(board , i , j , word , 0 )){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};