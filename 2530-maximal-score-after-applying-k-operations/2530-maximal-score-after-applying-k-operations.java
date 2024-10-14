class Solution {
    public long maxKelements(int[] nums, int k) {
        long sum=0;
        PriorityQueue<Integer> pq=new PriorityQueue<>((Integer i, Integer j)->{
            return j-i;
        });
        for(int i:nums){
            pq.add(i);
        }
        while(k!=0){
            int no=pq.poll();
            sum+=no;
            no=(int)Math.ceil((double)no/3);
            pq.add(no);
            k--;
        }
        return sum;
    }
}