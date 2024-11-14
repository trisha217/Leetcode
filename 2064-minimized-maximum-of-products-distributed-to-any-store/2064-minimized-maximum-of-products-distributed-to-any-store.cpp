#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minimizedMaximum(int numStores, std::vector<int>& quantities) {
        int minItemsPerStore = 1;
        int maxItemsPerStore = *std::max_element(quantities.begin(), quantities.end());

        // Binary search for the smallest feasible maximum items per store
        while (minItemsPerStore < maxItemsPerStore) {
            int midItems = (minItemsPerStore + maxItemsPerStore) / 2;
            int storesRequired = 0;

            // Calculate the total number of stores needed if each store can hold at most `midItems` items
            for (int quantity : quantities) {
                storesRequired += (quantity + midItems - 1) / midItems;
            }

            // Adjust binary search bounds based on whether the current max is feasible
            if (storesRequired <= numStores) {
                maxItemsPerStore = midItems; // Try a lower max items per store
            } else {
                minItemsPerStore = midItems + 1; // Increase min limit as current mid is too low
            }
        }

        return minItemsPerStore;
    }
};

auto optimizeIO = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();