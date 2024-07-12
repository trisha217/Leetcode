class Solution {
public:
    int solve(string& s, string p) {
        stack<int> st;
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!st.empty() && st.top() == p[0] && s[i] == p[1]) {
                st.pop();
                cnt++;
            } else {
                st.push(s[i]);
            }
        }
        s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return cnt;
    }
      
     int maximumGain(string s, int x, int y) {

    string high = x > y ? "ab" : "ba";
    string low = high == "ab" ? "ba" : "ab";
    return solve(s, high) * max(x, y) + solve(s, low) * min(x, y);
    }
};