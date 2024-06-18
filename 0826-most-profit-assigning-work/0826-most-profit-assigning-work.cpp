class Solution {
public:
    int bs(int& target, vector<pair<int, int>>& p) {
        int n = p.size();
        int low = 0;
        int high = n - 1;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (p[mid].first <= target) {
                ans = mid;
                low = mid + 1;

            } else
                high = mid - 1;
        }
        return ans;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        int w = worker.size();
        int score = 0;
        vector<pair<int, int>> p;
        
        for (int i = 0; i < difficulty.size(); i++) {
            p.push_back({difficulty[i], profit[i]});
        }
        sort(p.begin(), p.end());
// as we there is no direct relationship i.e diff is directly to profit, we may miss large profit,so for that
for(int i=1;i<p.size();i++){
    p[i].second=max(p[i].second,p[i-1].second);
}
        int res = 0;
        for (int i = 0; i < w; i++) {
            res = bs(worker[i], p);
            if (res != -1)
                score += p[res].second;
        }
        return score;
    }
};
