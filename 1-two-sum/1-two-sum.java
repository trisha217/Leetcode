class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] ar = new int[2];
        HashMap <Integer, Integer> hm = new HashMap<>();
        
        for(int i=0; i<nums.length; i++){
            if(hm.containsKey(target - nums[i])){
                ar[1] = i;
                ar[0] = hm.get(target - nums[i]);
            }
            hm.put(nums[i], i);        
        }
        return ar;
    }
}