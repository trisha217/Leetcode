class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int i = 0, j = n - 1, ans = n;

        if (n <= 1) return n;

        while (i < j) {
            if (s[i] == s[j]) {
                char ch = s[i];
                // Move inward as long as characters are equal
                while (i < j && s[i] == ch) ++i;
                while (i <= j && s[j] == ch) --j;
                ans = min(ans, j - i + 1);
            } else {
                // If characters at i and j are not equal, we cannot reduce further
                break;
            }
        }

        return ans;
    }
};