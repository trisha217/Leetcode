class Solution {
public:
    vector<int> diStringMatch(string s) {
        int lo =0;
        int hi = s.size();
        vector<int> ans;
        bool g = false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='I'){
                ans.push_back(lo++);
            }
            else if(s[i]=='D'){
                ans.push_back(hi--);
            }
            if (i == s.size() - 1) {
                if (g == false)  // boolean used so that we only enter this if ONCE ever.
                    --i;  // run last loop once more
                g = true;
            }
        }
        return ans;
    }
};