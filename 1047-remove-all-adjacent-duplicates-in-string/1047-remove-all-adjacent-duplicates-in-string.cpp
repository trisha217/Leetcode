class Solution {
public:
    string removeDuplicates(string a) {
        // stack<char> st;
        // for(auto i:s){
        //     if(st.empty()) 
        //         st.push(i);
        //     else if(st.top()==i)
        //         st.pop();
        //     else
        //         st.push(i);
        // }
        // string sn="";
        // while(!st.empty()){
        //     sn = sn + st.top();
        //     st.pop();
        // }
        // reverse(sn.begin(),sn.end());
        // return sn;
        
        stack<char> st;
	string ans="";
	for(auto curr:a) {
		if(st.empty()) st.push(curr);
		else if(st.top() == curr) st.pop();
		else st.push(curr);
	}

	while(!st.empty()) {
		ans += st.top();
		st.pop();
	}

	reverse(ans.begin(), ans.end());

	return ans;
    }
};