class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans="";
        int cnt1=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')
            cnt1++;
        }

        for(int i=0;i<s.size()-1;i++){
            if(cnt1>1){
                ans+='1';
                cnt1--;
            }
            else{
                ans+='0';
            }
        }
        ans+='1';
        return ans;
    }
};