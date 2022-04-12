class Solution {
    public int[][] generateMatrix(int n) 
    {
        int t = 1;
        int base = n, exponent = 2;
        int result = 1;
        while (exponent != 0) 
        {
            result *= base;
            --exponent;
        }
        int[][] mat = new int[n][n];
        int top = 0;
        int down = n-1;
        int left = 0;
        int right = n-1;
        int d = 0;
        while(left<=right && top<=down && t<=result)
        {
            if(d==0){
                for(int i = left; i<=right;i++){
                    mat[top][i] = t;
                    t++;
                }
                top+=1;
            }
            else if(d==1){
                for(int i = top; i<=down;i++){
                    mat[i][right] = t;
                    t++;
                }
                right-=1;
            }
            else if(d==2){
                for(int i = right; i>=left;i--){
                    mat[down][i] = t;
                    t++;
                }
                down-=1;
            }
             else if(d==3){
                for(int i = down; i>=top;i--){
                    mat[i][left] = t;
                    t++;
                }
                left+=1;
            }
            else{
                
            }
            d = (d+1)%4;
        }
        return mat;
    }
    
}