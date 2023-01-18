class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int value=minSubarraySum(nums);
        int value2=maxSubarraySum(nums);
        int sum=0;
        int max=Integer.MIN_VALUE;
        boolean allNegative=true;
        for(int val : nums){
            sum+=val;
            max=Math.max(max,val);
            if(val>=0){
                allNegative=false;
            }
        }
        if(allNegative){
            return max;
        }
        return Math.max(value2,Math.max(max,sum-value));
    }

    public int minSubarraySum(int[]arr){
        int min=Integer.MAX_VALUE;
        int sum=0;
        for(int i=0;i<arr.length;i++){
            sum+=arr[i];
            sum=Math.min(arr[i],sum);
            min=Math.min(min,sum);
        }
        return min;
    }
    public int maxSubarraySum(int[]arr){
        int max=Integer.MIN_VALUE;
        int sum=0;
        for(int i=0;i<arr.length;i++){
            sum+=arr[i];
            sum=Math.max(arr[i],sum);
            max=Math.max(max,sum);
        }
        return max;
    }

}