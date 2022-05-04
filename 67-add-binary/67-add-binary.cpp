class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        char c='0'; //carry
        int i=a.size()-1;
        int j=b.size()-1;
        while(i>=0 && j>=0){
            if(a[i]=='1' && b[j]=='1'){
                if(c=='0'){
                    ans+='0';
                    c='1';
                }
                else{
                    ans+='1';
                    c='1';
                }
            }
            else if(a[i]=='0' && b[j]=='0')
            {
                if(c=='0'){
                    ans+='0';
                    c='0';
                }
                else{
                    ans+='1';
                    c='0';
                }
            }
            else
            {
                if(c=='0'){
                    ans+='1';
                    c='0';
                }
                else{
                    ans+='0';
                    c='1';
                }
            }
            i--;
            j--;
        }
        while(i>=0){
            if(a[i]=='0'){
                if(c=='0'){
                    ans+='0';
                    c='0';
                }
                else{
                    ans+='1';
                    c='0'; 
                }
            }
            else{
                if(c=='0'){
                    ans+='1';
                    c='0';
                }
                else{
                    ans+='0';
                    c='1';
                }   
            }
            i--;
        }
        while(j>=0){
            if(b[j]=='0'){
                 if(c=='0'){
                    ans+='0';
                    c='0';
                }
                else{
                    ans+='1';
                    c='0'; 
                }
            }
            else{
                if(c=='0'){
                    ans+='1';
                    c='0';
                }
                else{
                    ans+='0';
                    c='1';
                }
            }
            j--;
        }
        if(c=='1'){
            ans+='1';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};