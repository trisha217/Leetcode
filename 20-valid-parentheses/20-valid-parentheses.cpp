class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int len = s.length();
        for(int i=0;i<len;i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
                continue;
            }
            if (st.empty())
                return false;
            char x;
            switch (s[i]) 
            {
                case ')':
                    x = st.top();
                    st.pop();
                    if (x == '{' || x == '[')
                        return false;
                    break;
 
                case '}':
                    x = st.top();
                    st.pop();
                    if (x == '(' || x == '[')
                        return false;
                        break;
 
                case ']':
                    x = st.top();
                    st.pop();
                    if (x == '(' || x == '{')
                        return false;
                        break;
            }
        }
        if(st.empty())
        {
            return true;
        }
        return false;        
    }
};