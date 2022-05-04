class Solution {
public:
    int maximum69Number (int num) {
        stringstream ss;  
        ss<<num;  
        string s;  
        ss>>s; 
        char nine='9';
        for(int i=0;i<s.size();i++){
            if(s[i]=='6'){
                char temp = s[i];
                s[i] = nine;
                nine = temp;
            }
        }
        int ans;
        stringstream obj;  
        obj << s; // insert data into obj  
        obj >> ans; 
        return ans;
    }
};