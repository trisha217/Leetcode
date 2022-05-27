class Solution {
public:
    int countSetBits(unsigned int n)
    {
        unsigned int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
    int hammingDistance(int x, int y) {
        int res = x ^ y;
        return countSetBits(res);
    }
};