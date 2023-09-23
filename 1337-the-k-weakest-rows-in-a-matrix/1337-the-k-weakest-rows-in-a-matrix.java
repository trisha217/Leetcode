class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        PriorityQueue<int[]> que = new PriorityQueue<>((a,b)->{
            if(a[0] > b[0] || (a[0] == b[0] && a[1] > b[1])){
                return 1;
            }
            else{
                return -1;
            }
        });
        for(int i = 0;i<mat.length;i++){
            int[] res = new int[2];
            int count = 0;
            for(int j = 0;j<mat[i].length;j++){
                if(mat[i][j] == 1)
                    count++;
            }
            res[0] = count;
            res[1] = i;
            que.offer(res);
        }
        int ans[] = new int[k];
        for(int i = 0;i<k;i++){
            ans[i] = que.poll()[1];
        }
        return ans;
    }
}