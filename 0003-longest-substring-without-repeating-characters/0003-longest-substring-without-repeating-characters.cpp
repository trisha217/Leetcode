class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        int maxLen = 0;
        vector<int> hash(256,-1);
        int len = 0;
        while(r<s.size()){
            //it's there in the map
            if(hash[s[r]] != -1){
                //it's after l, then move l
                if(hash[s[r]] >= l){
                    l = hash[s[r]] + 1;
                }  
            }
            len = r - l + 1;
            maxLen = max(maxLen,len);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};