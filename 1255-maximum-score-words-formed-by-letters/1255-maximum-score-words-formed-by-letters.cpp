class Solution {
public:
    int solve(vector<string> words, vector<int> v, vector<int> score, int i)
    {
        if (i >= words.size())
        {
            return 0;
        }
        vector<int> t = v;
        int sum = 0;
        int j = 0;
        int t1 = 0;
        int t2 = 0;
        for (j;j<words[i].length();j++)
        {
            if (t[words[i][j] - 'a'] == 0)
            {
                break;
            }
            t[words[i][j] - 'a']--;
            sum = sum + score[words[i][j] - 'a'];
        }
        if (j == words[i].length())
        {
            t1 = sum + solve(words, t, score, i+1);
        }
        t2 = solve(words, v, score, i+1);
        return max(t1, t2);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> v (26, 0);
        for (int i = 0;i<letters.size();i++)
        {
            v[letters[i]-'a']++;
        }
        return solve(words, v, score, 0);
    }
};