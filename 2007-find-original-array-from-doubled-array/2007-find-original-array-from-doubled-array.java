class Solution {
    public int[] findOriginalArray(int[] changed) {
        int[] varr = new int[0];
        int n = changed.length;
        if(n%2==1){
            return varr;
        }
        int[] ans = new int[n/2];
        HashMap<Integer,Integer> hm = new HashMap<>();
        for(int i=0;i<n;i++){
            hm.put(changed[i],hm.getOrDefault(changed[i],0)+1);
        }
        Arrays.sort(changed);
        int temp = 0;
        for(int i: changed)
        {
            if(hm.get(i)<=0){
                continue;
            }
            if(hm.getOrDefault(i*2,0)<=0){
                return varr;
            }
            ans[temp++] = i;
            hm.put(i, hm.get(i)-1); 
            hm.put(2*i, hm.get(2*i)-1);
        }
        return ans;
    }
}