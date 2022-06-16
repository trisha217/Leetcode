class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string sn="";
        for(auto i:s){
            if(st.empty()) st.push(i);
            else if(st.top()==i) st.pop();
            else st.push(i);
        }
        while(!st.empty()){
            sn+= st.top();
            st.pop();
        }
        reverse(sn.begin(),sn.end());
        return sn;
        
    }
};