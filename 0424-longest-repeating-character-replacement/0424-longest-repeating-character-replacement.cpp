class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxlen=0;
        int maxf = 0;
        map<char,int> mpp;
        while(r < s.size()){
            mpp[s[r]]++;
            maxf = max(maxf,mpp[s[r]]);
            int len = r - l + 1;
            if(len - maxf > k){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0){
                    mpp.erase(s[l]);
                }
                l++;
            }
            if(len - maxf <= k){
                maxlen = max(maxlen,r - l + 1);
            }
            r++;
        }
        return maxlen;
    }
};
