class Solution {
    public void moveZeroes(int[] nums) {
        
        int swap=0;
        
        for(int i=0, j=0; i<nums.length-1 && j!=nums.length;j++) {
            if(nums[j]!=0) {
                swap=nums[i];
                nums[i]=nums[j];
                nums[j]=swap;
                i++;
            }
        }
    }
}