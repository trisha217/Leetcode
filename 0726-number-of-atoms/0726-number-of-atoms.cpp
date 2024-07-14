class Solution {
public:
    bool number(char c){
        if(c<='9' && c>='0')
            return true;
        return false;
    }
    map<string,int> solve(string& s){
        map<string,int> mp;
        int i=0;
        while(i<s.length()){
            if(s[i]=='('){
                int j=i+1;
                int op=0;
                while(op>0 || s[j]!=')'){
                    if(s[j]=='(')
                        op++;
                    if(s[j]==')')
                        op--;
                    j++;
                }
                string t=s.substr(i+1,j-i-1);
                map<string,int> temp=solve(t);
                i=j+1;
                int num=0;
                while(i<s.length() && number(s[i])){
                    num=num*10+int(s[i]-'0');
                    i++;
                }
                if(num==0)
                    num=1;
                for(auto& item:temp){
                    mp[item.first]+=(item.second*num);
                }
            }
            else{
                string str;
                str+=s[i];
                i++;
                while(s[i]>='a' && s[i]<='z'){
                    str+=s[i];
                    i++;
                }
                int num=0;
                while(i<s.length() && number(s[i])){
                    num=num*10+int(s[i]-'0');
                    i++;
                }
                if(num==0)
                    num=1;
                mp[str]+=num;

            }
        }    
        return mp;    
    }
    string countOfAtoms(string& formula) {
        map<string,int> mp=solve(formula);
        string ans;
        for(auto& item:mp){
            ans+=item.first;
            if(item.second>1){
                ans+=to_string(item.second);
            }
        }
        return ans;
        
    }
};