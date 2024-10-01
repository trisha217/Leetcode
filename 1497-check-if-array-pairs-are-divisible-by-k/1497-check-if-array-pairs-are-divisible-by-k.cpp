class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
         unordered_map<int, int> remainderCount;
    
    // Step 1: Calculate remainders and count their frequencies
    for (int num : arr) {
        int remainder = ((num % k) + k) % k; // Handle negative numbers
        remainderCount[remainder]++;
    }

    // Step 2: Check conditions for valid pairing
    for (auto& entry : remainderCount) {
        int remainder = entry.first;
        int count = entry.second;

        // Case 1: If the remainder is 0, there must be an even number of such elements
        if (remainder == 0) {
            if (count % 2 != 0) {
                return false;
            }
        }
        // Case 2: For other remainders, the count of elements with remainder `r`
        // must match the count of elements with remainder `k - r`
        else if (remainderCount[remainder] != remainderCount[k - remainder]) {
            return false;
        }
    }

    // If all conditions are satisfied, return true
    return true;
    }
};