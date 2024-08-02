class Solution {
public:
    // Function to convert a binary string to a numerical array
    vector<int> binaryStringToNumArray(const string &binaryStr) {
        vector<int> numArray;
        for (char ch : binaryStr) {
            if (ch == '0' || ch == '1') {
                numArray.push_back(ch - '0');  
            } else {
                cerr << "Invalid character in binary string: " << ch << endl;
            }
        }
        return numArray;
    }
    int secondsToRemoveOccurrences(string s) {
        vector<int> nums = binaryStringToNumArray(s);
        int cnt = 0, seconds = 0;
        while (true) {
            bool moved = false;
            for (int i = 0; i < nums.size() - 1; ++i) {
                if (nums[i] == 0 && nums[i + 1] == 1) {
                    swap(nums[i], nums[i + 1]);
                    ++i;  // Skip next element to avoid double counting
                    moved = true;
                }
            }
            if (!moved) break;
            ++seconds;
        }
        return seconds;
    }
};