class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int arr[26] = {0};
        for (char &ch: chars) arr[ch-'a']++;
        int sz = chars.size();
        int ans = 0;
        for (string &s: words) {
            if (s.size() > sz) continue;
            int freq[26];
            for (int i = 0; i < 26; ++i) {
                freq[i] = arr[i];
            }
            bool flag = false;
            for (char &ch: s) {
                if (freq[ch-'a']>0) freq[ch-'a']--;
                else {
                    flag = true;
                    break;
                }
            }
            if (flag) continue;
            ans += s.size();
        }
        return ans;
    }
};