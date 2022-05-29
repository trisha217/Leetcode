class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> ans(t.size(),0);
        stack<int> st;
        int i= 0;
        while (i<t.size())
        {
            if (st.empty() || t[st.top()] >= t[i])
            {
                st.push(i);
                i++;
            }
            else
            {
                int t = st.top();
                st.pop();
                ans[t] = i - t;
            }
        }
        return ans;
    }
};