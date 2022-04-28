class Solution {
public:
    string sortString(string s) {
        int n = s.size();
        int freq[26]={0};
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        string temp="";
        while(n>0)
        {
                for(int i=0;i<26;i++)
                {
                    if(freq[i]!=0)
                    {
                        temp+=((char)(i+97));
                        freq[i]--;
                        n--;
                    }  
                    
                }
                for(int i=25;i>=0;i--)
                {
                    if(freq[i]!=0)
                    {
                        temp+=((char)(i+97));
                        freq[i]--;
                         n--;
                    }  
                   
                }
        }
        return temp;
    }
};