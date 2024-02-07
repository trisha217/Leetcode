
class Solution {
public:
    string frequencySort(string s) {
        vector<int> count(256, 0);
        priority_queue<pair<int, char>> pq;
        string res;
        for (const char ch : s) count[ch]++;
        for (int i = 0; i < 256; i++) {
            if (count[i] > 0) pq.push({count[i], char(i)});
        }
        while (!pq.empty()) {
            int freq = pq.top().first;
            int ch = pq.top().second;
            pq.pop();
            while (freq--) res += ch;
        }
        return res;
    }
};