class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res = "";
        int oc = 0;
        for(char c:s){
            if(c==')'){
                if(oc>=1){
                    res.push_back(c);
                    oc--;
                }
            }
            else if(c=='('){
                oc++;
                res.push_back(c);
            }
            else{
                res.push_back(c);
            }
        }
        cout<<res;
        if(oc!=0){
            string temp = res;
            res = "";
            int n = temp.size();
            for(int i=n-1; i>=0; i--){
                if(oc>=1 && temp[i]=='('){
                    oc--;
                    continue;
                }
                res.push_back(temp[i]);
            }
            reverse(res.begin(), res.end());
        }
        return res;
    }
};