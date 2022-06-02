class Solution {
    public int[][] transpose(int[][] mat) {
        int M = mat.length, N = mat[0].length;
        int[][] copy = new int[N][M];
        for (int j = 0; j < N; j++)
            for (int i = 0; i < M; i++)
                copy[j][i] = mat[i][j];
        return copy;
    }
}