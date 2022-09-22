class Solution {
    public int[] plusOne(int[] digits) {
        int add = 1;
        for(int i=digits.length-1;i>=0;i--){
            digits[i] = digits[i] + add;
            if(digits[i]<=9){
                return digits;
            }
            digits[i]=0;
        }
        //if at the end digits becomes 99999....99 then we should return 10000000..000
        //so doing this in this way
        int[] ret = new int[digits.length+1];
        ret[0] = 1;
        return ret;
    }
}