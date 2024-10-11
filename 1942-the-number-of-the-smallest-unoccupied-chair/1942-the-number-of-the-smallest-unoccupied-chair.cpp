auto _ = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<tuple<int, bool, int>> moves;
        moves.reserve(n);
        int arrival_time = times[targetFriend].front();
        for (int i = 0; i < n; ++i) {
            const auto& t = times[i];
            int a = t.front(), d = t[1];
            if (a <= arrival_time) {
                moves.emplace_back(a, true, i); // arrival
                if (d <= arrival_time) {
                    moves.emplace_back(d, false, i); // departure
                }
            }
        }
        sort(moves.begin(), moves.end());
        priority_queue<int, vector<int>, greater<int>> q;
        vector<int> chair_assignments(n, -1);
        int num_seated = 0;
        // for (int i = 0; i < n; ++i) q.push(i);
        for (const auto& m : moves) {
            int f = get<2>(m);
            if (get<1>(m)) {
                if (q.empty()) {
                    chair_assignments[f] = num_seated;
                } else {
                    chair_assignments[f] = q.top();
                    q.pop();
                }
                if (f == targetFriend) {
                    return chair_assignments[f];
                }
                ++num_seated;
            } else {
                int& ca = chair_assignments[f];
                q.push(ca);
                ca = -1;
                --num_seated;
            }
        }
        throw;
    }
};