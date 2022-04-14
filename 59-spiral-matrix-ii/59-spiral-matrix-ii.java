class Solution {
    public int[][] generateMatrix(int n) {
        int[][] arr=new int[n][n];
        int x=1;
        int top=0,left=0,right=n-1,down=n-1;
        while(top<=down && left<=right){
            for(int i = top;i<=right;i++){
                arr[top][i] = x++;
            }
            for(int i=top+1;i<=down;i++)
                arr[i][right] = x++;
            if(top == down || left==right)
                break;
            for(int i=right-1;i>=left;i--)
                arr[down][i]=x++;
            for(int i=down-1;i>top;i--)
                arr[i][left] = x++;
            top++;
            left++;
            down--;
            right--;
        }
        return arr;
    }
}