class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(auto &ch:word)
        {
            freq[ch-'a']++;
        }
        int result=0;
        sort(begin(freq),end(freq),greater<int>());
        for(int i=0;i<26;i++)
        {
            int f=freq[i];
            int press=(i/8)+1;
            result+=f*press;
        }
        return result;
    }
};
