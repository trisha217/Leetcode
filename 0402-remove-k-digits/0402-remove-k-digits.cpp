class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        stack<char> st;
        int n = num.size();
        //base case
        if(k>=n){
            return "0";
        }
        //insert characters in stack
        for(auto &it: num){
            while(k>0 && !st.empty() && st.top()>it){
                st.pop();
                --k;
            }
            st.push(it);
        }
        //remove k digits from last now, since we have exhausted our string "num"
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        //now pop the elements from stack
        while(!st.empty()){
            ans+=string(1, st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        //remove leading zeros
        while(ans.size()!=0 && ans[0]=='0'){
            ans.erase(0,1);
        }
        // if the resulting string ans is empty, it returns "0". Otherwise, it returns ans itself
        return ans==""?"0":ans;
    }
};