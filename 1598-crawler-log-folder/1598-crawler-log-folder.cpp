class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        int n=logs.size();
        for(int i=0;i<n;i++){
            if(logs[i][0] != '.'){
                st.push(logs[i]);
            }
            if(!st.empty() && (logs[i] == "../")){
                st.pop();
            }
        }
        return st.size();
    }
};