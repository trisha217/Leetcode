class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int l1=s.size();
        int l2 = t.size();
        stack<char> st1;
        stack<char> st2;
        for(int i=0;i<l1;i++){
            if(s[i]=='#' && !st1.empty()){
                st1.pop();   
            }
            else{
                st1.push(s[i]);
            }
        }
        for(int i=0;i<l2;i++){
            if(t[i]=='#' && !st2.empty()){
                st2.pop();   
            }
            else{
                st2.push(t[i]);
            }
        }
        // while(m1<l1){
        //     if(s[m1]=='#'){
        //         st1.pop();
        //     }
        //     else{
        //         break;
        //     }  
        //     m1++;
        // }
        // while(m2<l2)
        // {
        //     if(t[m2]=='#'){
        //         st2.pop();
        //     }
        //     else{
        //         break;
        //     }
        //     m2++;
        // }
        string n1="";
        string n2="";
        while(!st1.empty()){
            if(st1.top()!='#'){
                n1+=st1.top();
                st1.pop();
            }
            else{
                st1.pop();
            }
        } 
        reverse(n1.begin(), n1.end());
        while(!st2.empty()){
            if(st2.top()!='#'){
                 n2+=st2.top();
                 st2.pop();
            }
            else{
                st2.pop();
            }
        }
       reverse(n2.begin(), n2.end());
        cout<<n1<<n2;
        if(n1==n2){
            return true;
        }
        else{
            return false;
        }
        
    }
};