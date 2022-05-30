class Solution {
public:
    int divide(int divd, int divs) {
        // When given dividend is -INFINITY and divisor is -1. The
        // answer should be -Inf*-1=Inf
        if(divd == INT_MIN and divs == -1){
            return INT_MAX;
        }
        // If dividend and divisor are both positive/negative
        // total is positive, else not.
        bool positiveSign = (divd < 0 == divs < 0);
        // since we know what sign the result should be,
        // we can remove the negative sign from both divisor and dividend
        long dividend = abs(divd);
        long divisor = abs(divs);
        // our final answer will be 'ans', the number of times we need to multiply
        // divisor to make dividend as close to 0 as possible.
        long ans = 0;
        
        // while dividend is less/equal to divisor do the following:
        while(dividend >= divisor){
            // take a copy of divisor. we're not modifying divisor,
            // because we still need to check if dividend is greater/equal to
            // our original divisor
            long divisor2 = divisor;
            // divisorMultipliedBy tells us how many times we can double
            // divisor so as to keep it less than dividend.
            // for example: 3x2=6. 3 doubled is 6, which is still less than 10
            long divisorMultipliedBy = 1;
            
            // while dividend is greater than double the divisor2 do the following:
            while(dividend >= (divisor2 << 1)){
                // double the divisor2, if it was 3 at first, make it 6
                divisor2 = divisor2 << 1;
                // Since we doubled divisor, store the amount of how many times
                // we multiplied divisor.
                // 3 doubled once=6, so we multiplied divisor by 2.
                // 3 doubled twice=12. So we multiplied 3 by 4.
                divisorMultipliedBy = divisorMultipliedBy << 1;
            }
            // divisorMultipliedBy should now have the number of times
            // we multiplied divisor to get a value less than dividend.
            ans+= divisorMultipliedBy;
            // so if now divisor2 is 6, after doubling once.
            // dividend was 10, but after subtracting dividend will become 10-6=4.
            // So now 4 is dividend, 3 is divisor and we try to find out the number
            // of multiplications again and add them up.
            // In the second iteration, we'll multiply 3 by 1. So now it'll be
            // 4-3=1. dividend is now as close to 0 as possible and is also less
            // than divisor. So, our final ans is 3. We x2 the 3 once and now x1.
            dividend -= divisor2;
        }
                  
        // if PositiveSign was true, then we return ans as is.
        if(positiveSign){
            return ans;
        }
        // otherwise, multiply by -1 (you can also directly write `return -ans`
        return ans * -1;
    }
};