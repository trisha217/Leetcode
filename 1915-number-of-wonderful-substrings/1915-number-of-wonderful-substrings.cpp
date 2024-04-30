class Solution {
public:
    long long wonderfulSubstrings(string word) {
        // Initialize an array to store count of each XOR value
        vector<long long> count(1024, 0); // 2^10 to store XOR values
        
        long long result = 0; // Initialize the result
        int prefixXor = 0; // Initialize prefix XOR value
        count[prefixXor] = 1; // Initialize count of prefix XOR value

        // Iterate through each character in the word
        for (char ch : word) {
            // Calculate the index of the character in the alphabet
            int charIndex = ch - 'a';
            // Update the prefix XOR value
            prefixXor ^= 1 << charIndex;
            // Increment the result by count of prefix XOR value
            result += count[prefixXor];
            
            // Iterate through all possible XOR values by toggling one bit at a time
            for (int i = 0; i < 10; i++) {
                result += count[prefixXor ^ (1 << i)];
            }
            // Increment the count of current prefix XOR value
            count[prefixXor]++;
        }

        return result; // Return the final result
    }
};