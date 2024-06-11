class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
        // Create a map to store the position of each element in arr2
        std::unordered_map<int, int> pos;
        for (int i = 0; i < arr2.size(); ++i) {
            pos[arr2[i]] = i;
        }

        // Custom comparator
        auto comp = [&pos](int a, int b) {
            if (pos.count(a) && pos.count(b)) {
                return pos[a] < pos[b]; // Both a and b are in arr2
            }
            if (pos.count(a)) {
                return true; // Only a is in arr2
            }
            if (pos.count(b)) {
                return false; // Only b is in arr2
            }
            return a < b; // Neither a nor b is in arr2, sort in ascending order
        };

        // Sort arr1 using the custom comparator
        std::sort(arr1.begin(), arr1.end(), comp);

        return arr1;
    }
};