class Solution {
    public void setZeroes(int[][] matrix) {
        int col=matrix[0].length;
        int row=matrix.length;
        int[] col1 = new int[col];
        int[] row1 = new int[row];
        for(int i=0;i<col;i++){
            col1[i]=1;
        }
        for(int i=0;i<row;i++){
            row1[i]=1;
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    row1[i]=0;
                    col1[j]=0;
                }
            }
        }
        for(int i=0;i<row;i++){
            if(row1[i]==0){
                for(int k=0;k<col;k++){
                    matrix[i][k]=0;
                }
            }
        }
        for(int i=0;i<col;i++){
            if(col1[i]==0){
                for(int k=0;k<row;k++){
                    matrix[k][i]=0;
                }
            }
        }
    }
}