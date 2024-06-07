class Solution {
public:
    string replaceWords(vector<string>& dic, string sen) {
        int n  = sen.size();
        unordered_map<string, int>mp;
        for(auto it:dic) mp[it]++;
        string str = "";

        // Storing each string of sentence in vector
        vector<string>v;
        for(int i=0; i<n; i++){
            str += sen[i];
            if(sen[i] == ' ' || i == n-1){
                if(sen[i] == ' ') str.pop_back();
                v.push_back(str);
                str = "";
            }
        }

        string res = "";
        for(auto it: v){
            string st = "";
            for(int i=0; i<it.size(); i++){
                if(mp[st]) {
                    res += st;
                    res += " ";
                    break;
                }
                st += it[i];
                if(i == it.size()-1){
                    res += st;
                    res += " ";
                    break;
                } 
            }
        }
        res.pop_back();
        return res;
    }
};