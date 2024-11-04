class Solution {
public:
    string compressedString(string s) {
        int n=s.size();
        int i=0;
        int j=0;
        string comp="";
        while(i<n)
        {
            int cnt=0;
            while(cnt<9&&j<n&&s[i]==s[j])
            {
                cnt++;
                j++;
            }
            comp+=to_string(cnt)+s[i];
            i=j;
        }
        return comp;

    }
};