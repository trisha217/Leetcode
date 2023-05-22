class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int>hashMap;
        for(auto &num : nums)
        {
            hashMap[num]++;
        }

        priority_queue<pair<int, int>>maxHeap;

        for(auto &hashPair : hashMap)
        {
            int key = hashPair.first;
            int value = hashPair.second;
            maxHeap.push({value, key});
        }

        vector<int>k_most_frequent_elements;
        while(k--)
        {
            int most_frequent_element = maxHeap.top().second;
            maxHeap.pop();
            k_most_frequent_elements.push_back(most_frequent_element);
        }
        return k_most_frequent_elements;
    }
};