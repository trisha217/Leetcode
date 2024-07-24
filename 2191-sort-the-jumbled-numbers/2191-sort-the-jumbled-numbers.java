class Solution {
    public int[] sortJumbled(int[] mapping, int[] nums) {
        int arr[][]=new int[nums.length][2];
        for(int i=0;i<nums.length;i++){
            int x=nums[i];
             var sb=new StringBuilder();
            for(char c:Integer.toString(x).toCharArray()){  
                sb.append(Integer.toString(mapping[c-'0']));
            }
            arr[i][0]=x;
            arr[i][1]=Integer.parseInt(sb.toString());
        }
        int ans[]=new int[nums.length];
        Arrays.sort(arr,(a,b)->a[1]-b[1]);
        int i=0;
        for(int[] y:arr){
            ans[i]=y[0];
            i++;
        }
        return ans;
    }
}