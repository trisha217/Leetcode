// Explanation: The number we are searching for is any number from zero to length of array. If we sort the array in ascending order, we can iterate through it from left to right checking if the number of elements until the end and the current value meet the conditions of success. Those are:

// The number of elements from the current index until the end is less than or equal the current value in the array
// The number of elements from the current index until the end is greater than the previous value in the array (if it exists)
// We are, essentially, cleverly checking if the current number of elements until the end is the answer.

class Solution {
    public int specialArray(int[] nums) {
        Arrays.sort(nums);
        for(int i = 0; i < nums.length; i++) {
            int n = nums.length-i;
            boolean cond1 =  n<=nums[i];
            boolean cond2 = (i-1<0) || (n>nums[i-1]);
            if (cond1 && cond2) return n;
        }
        return -1;
    }

}