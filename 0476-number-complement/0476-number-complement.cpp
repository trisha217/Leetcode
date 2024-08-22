class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1;  // Special case: Complement of 0 is 1
    
        // Calculate the number of bits in the binary representation of num
        unsigned int bits = log2(num) + 1;

        // Create a mask with all bits set to 1 of the same length as num
        unsigned int mask = (1U << bits) - 1;

        // XOR num with the mask to get the complement
        return num ^ mask;
    }
};