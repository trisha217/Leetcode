class Solution {
public:
    string minWindow(string s, string t) {
        int l=0,r=0,cnt=0,minlen =1e9;
        int k=0;
        int sIndex = -1;
        map<char,int> mpp;
        while(k < t.size()){
            mpp[t[k]]++;
            k++;
        }
        while(r<s.size()){
            if(mpp[s[r]] > 0){
                cnt = cnt + 1;
            }
            mpp[s[r]]--;
            while(cnt == t.size()){
                int len = r - l + 1;
                if(len < minlen){
                    minlen = len;
                    sIndex = l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]] > 0){
                    cnt--;
                }
                l++;
            }
            r++;    
        }
        if(sIndex == -1){
            return "";
        }
        return s.substr(sIndex,minlen);
    }
};