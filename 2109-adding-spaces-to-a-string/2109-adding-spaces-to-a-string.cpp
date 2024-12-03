class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int l = s.size() + spaces.size();
        char ans[l];
        int sIndex = 0, spacesIndex = 0, ansIndex = 0;

        while (sIndex < s.size()) {
            if (spacesIndex < spaces.size() && sIndex == spaces[spacesIndex]) {
                ans[ansIndex++] = ' ';
                spacesIndex++;
            }
            ans[ansIndex++] = s[sIndex++];
        }
        return string(ans, l);
    }
};