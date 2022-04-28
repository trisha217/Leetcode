class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        if(n==2){
            return "11";
        }
        string s = "11";
        for(int i=3;i<=n;i++){
            s=s+"#";
            string temp="";
            int count=1;
            for(int j=1;j<s.size();j++){
                if(s[j]!=s[j-1])
                {
                    temp+=to_string(count);
                    temp+=s[j-1];
                    count=1;
                    
                }   
                else{
                    count++;
                }
            }
            s= temp;
        }
        return s;
        
    }
};