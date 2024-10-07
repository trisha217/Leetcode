class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if((!st.empty() && s[i]=='B' && st.top()=='A') || (!st.empty() && s[i]=='D' && st.top()=='C'))
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
            
        }
        return st.size();
    }
};