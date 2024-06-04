class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.length();
        map<char,int>mp;
        for(int i=0;i<n;i++)
        {
           mp[s[i]]++;
        }
        int count=0;
        int oddCount=0;
        for(auto i:mp)
        {
           if(i.second>1)
           {
              count+=i.second;
               if(i.second%2!=0)
               {
                  count-=1;
                  oddCount=1;
               }
           }
           else
           {
             oddCount=1;
           }
        }
        if(oddCount==0)
        {
          return count;
        }
        else
        {
          return count+1; 
        }
    }
};