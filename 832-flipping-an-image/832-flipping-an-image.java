class Solution {
    public int[][] flipAndInvertImage(int[][] image) {
        int col=image[0].length;
        int row=image.length;
        int mat[][] = new int[row][col];
        for(int i=0;i<row;i++){
            for(int j=col-1,k=0;j>=0;j--,k++){
                mat[i][k]=image[i][j];
                if(mat[i][k]==0){
                    mat[i][k]=1;
                }
                else{
                    mat[i][k]=0;
                }
            }
        }
        return mat;
    }
}