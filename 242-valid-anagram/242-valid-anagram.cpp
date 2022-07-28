class Solution {
public:
    bool isAnagram(string s, string t) {
          unordered_map<char,int> mp;
        if(s.size()!=t.size()){
            return false;
        }
        for(int i=0;i<s.size();i++){
            char c= s[i];
            mp[c]++;
        }
        for(int i=0;i<t.size();i++){
            char d = t[i];
            if(mp[d]>0){
                mp[d]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};