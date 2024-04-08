class Solution {
public:
    bool checkValidString(string s) {
        stack<int>sym;
        stack<int>ast;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') sym.push(i);
            else if(s[i]=='*') ast.push(i);
            else if(s[i]==')' && (!sym.empty())){
                sym.pop();
            } 
            else if(s[i]==')' && (!ast.empty())){
                ast.pop();
            }
            else  return false;
        }
         while(!sym.empty())
           { if(ast.empty()) return false;
            int sy = sym.top();
                int as = ast.top();
            if(sy<as){
                sym.pop(); ast.pop();
            }
            else return false;
           }
        if(sym.empty()) return true;
        else return false;
    }
};