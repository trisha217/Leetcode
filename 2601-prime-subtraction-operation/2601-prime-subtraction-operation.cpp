class Solution {
public:
    // to store precomputed primes
    vector<bool> isPrime = vector<bool>(1002, true);

    // Sieve of Eratosthenes
    void calcPrime(int n) {
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i < n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }
    
    // get largest prime strictly lesser than num
    int get(int num) {
        if (num < 2) return 0;
        for (int i = num - 1; i >= 2; --i) {
            if (isPrime[i]) return i;
        }
        return 0;
    }

    bool primeSubOperation(vector<int>& nums) {
        calcPrime(1001); 
        
        // make every element as small as possible but greater than the previous element
        for(int i=0; i<nums.size(); i++){
            int num = i > 0 ? nums[i] - nums[i-1] : nums[i];
            int p = get(num);
            nums[i] -= p; 
        }

        // check if array is strictly increasing
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) return false;
        }
        return true;
    }
};