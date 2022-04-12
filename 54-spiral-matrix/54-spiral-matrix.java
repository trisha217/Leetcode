class Solution {
    public List<Integer> spiralOrder(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
         List<Integer> ans=new ArrayList<Integer>();  
        int top = 0;
        int down = m-1;
        int left = 0;
        int right = n-1;
        int d = 0;
        while(left<=right && top<=down)
        {
            if(d==0){
                for(int i = left; i<=right;i++){
                    ans.add(mat[top][i]);
                }
                top+=1;
            }
            else if(d==1){
                for(int i = top; i<=down;i++){
                    ans.add(mat[i][right]);
                }
                right-=1;
            }
            else if(d==2){
                for(int i = right; i>=left;i--){
                    ans.add(mat[down][i]);
                }
                down-=1;
            }
             else if(d==3){
                for(int i = down; i>=top;i--){
                    ans.add(mat[i][left]);
                }
                left+=1;
            }
            else{
                
            }
            d = (d+1)%4;
        }
        return ans;
        
    }
}