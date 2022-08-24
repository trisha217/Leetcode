class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n>=3){
            if(n%3 != 0){
                return false;
            }
            n= n/3;
        }
        return n==1;
    }
};


// Method 2

// If log10(n) / log10(3) returns an int (more precisely, a double but has 0 after decimal point), then n is a power of 3. (original post). But be careful here, you cannot use log (natural log) here, because it will generate round off error for n=243. This is more like a coincidence. I mean when n=243, we have the following results:

// log(243) = 5.493061443340548    log(3) = 1.0986122886681098
//    ==> log(243)/log(3) = 4.999999999999999

// log10(243) = 2.385606273598312    log10(3) = 0.47712125471966244
//    ==> log10(243)/log10(3) = 5.0
// This happens because log(3) is actually slightly larger than its true value due to round off, which makes the ratio smaller.

// public boolean isPowerOfThree(int n) {
//     return (Math.log10(n) / Math.log10(3)) % 1 == 0;
// }