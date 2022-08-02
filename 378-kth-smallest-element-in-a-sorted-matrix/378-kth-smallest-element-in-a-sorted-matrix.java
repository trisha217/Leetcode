class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int s=0;
        for(int i=0; i< matrix.length; i++){
            for(int j=0; j< matrix[0].length; j++){
                pq.add(matrix[i][j]);
            }
        }
        while(k>0){
            s = pq.peek();
            pq.poll();
            k--;
        }
        return s;
    }
}