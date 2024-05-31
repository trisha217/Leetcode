class Solution {
    public int[] singleNumber(int[] nums) {
                Set<Integer> set = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            boolean check = set.add(nums[i]);
            if (!check) {
                set.remove(nums[i]);
            }
        }
        int[] arr = new int[set.size()];
        int i = 0;
        for (int x : set) {
            arr[i++] = x;
        
        } 
        return arr;   
    }
}