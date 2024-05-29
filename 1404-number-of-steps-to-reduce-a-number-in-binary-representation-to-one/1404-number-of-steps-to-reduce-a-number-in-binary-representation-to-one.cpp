class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        while(s!="1"){
            ans++;
            if(s[s.size()-1]=='1'){    //odd
                int j=s.size()-1;
                while(j>=0 and s[j]!='0'){
                    s[j]='0';
                    j--;
                }
                if(j>=0)
                    s[j]='1';
                else
                    s="1"+s;
            }
            else if(s[s.size()-1]=='0')  //even
                s.resize(s.size()-1);
        } 
        return ans;
    }
};
