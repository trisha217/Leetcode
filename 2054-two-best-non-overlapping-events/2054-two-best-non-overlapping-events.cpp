class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int vals[events.size()];
        int maxValue = 0, answer = 0, n=events.size();
        for (int i=n-1; i>=0; --i) {
            if (maxValue < events[i][2]) {
                maxValue = events[i][2];
            }
            vals[i] = maxValue;
        }
        for (int i=0; i<n; i++) {
            int currValue = events[i][2], left = i+1, right = n-1, end = events[i][1];
            while (left <= right) {
                int mid = (left+right)/2;
                if (events[mid][0] > end) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            currValue += (left < n) ? vals[left] : 0;
            if (currValue > maxValue) {
                maxValue = currValue;
            }
        }
        return maxValue;
    }
};