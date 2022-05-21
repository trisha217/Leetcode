class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n>0 && !(n & n-1) && n%3==1){
            return true;
        }
        else{
            return false;
        }
    }
};