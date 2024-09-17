class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> m;
        string s="";
        for(auto x:s1){
            if(x==' '){
                m[s]++;
                s="";
            }
            else
                s+=x;
        }
        m[s]++;
        s="";
        for(auto x:s2){
            if(x==' '){
                m[s]++;
                s="";
            }
            else
                s+=x;
        }
        m[s]++;
        vector<string> ans;
        for(auto x:m){
            if(x.second==1)
                ans.push_back(x.first);
        }
        return ans;
    }
};