class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;
        return wordBreakHelper(s, wordSet, 0, memo);
    }

private:
    vector<string> wordBreakHelper(const string& s, const unordered_set<string>& wordDict, int start, unordered_map<int, vector<string>>& memo) {
        if (start == s.length()) {
            return {""};
        }

        if (memo.find(start) != memo.end()) {
            return memo[start];
        }

        vector<string> result;
        for (int end = start + 1; end <= s.length(); end++) {
            string word = s.substr(start, end - start);
            if (wordDict.find(word) != wordDict.end()) {
                vector<string> nextWords = wordBreakHelper(s, wordDict, end, memo);
                for (const string& next : nextWords) {
                    result.push_back(word + (next.empty() ? "" : " ") + next);
                }
            }
        }

        memo[start] = result;
        return result;
    }
};