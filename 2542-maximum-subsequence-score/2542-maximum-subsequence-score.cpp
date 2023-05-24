class Solution {
public:
    static bool comp(pair<int, int> &a, pair<int, int> &b) {
        return a.first > b.first;
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> v;
        
        for(int i = 0; i < n; i++) v.push_back({nums2[i], nums1[i]});
        sort(v.begin(), v.end(), comp);

        priority_queue<int, vector<int>, greater<int>> pq;

        long long sum = 0, ans = 0;
        for(int i = 0; i < k - 1; i++) {
            sum += v[i].second;
            pq.push(v[i].second);
        }

        for(int i = k - 1; i < n; i++) {
            sum += v[i].second;
            pq.push(v[i].second);
            ans = max(ans, sum * v[i].first);

            sum -= pq.top();
            pq.pop();
        }

        return ans;
    }
};