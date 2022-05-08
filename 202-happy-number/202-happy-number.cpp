class Solution {
public:
    int digitsum(int n) {
        int res = 0;
        while(n > 0) {
            res = res + (n % 10) * (n % 10);
            n = n / 10;
        }
        return res;
    }
    
    bool isHappy(int n) {
        while(1) {
            if(n == 89) 
                return false;
            if(n == 1) 
                return true;
            n = digitsum(n);
        }
        
    }
};