class Solution {
public:
    bool isValid(string s) {
        if(s.size() <= 1){
            return false;
        }
        stack<char> stack;
        for(int i = 0; i < s.size(); i++){
            if(stack.empty() == true){
                stack.push(s[i]);
            }else{
                if(stack.top() == '(' && s[i] == ')'){
                    stack.pop();
                    continue;
                }
                if(stack.top() == '[' && s[i] == ']'){
                    stack.pop();
                    continue;
                }
                if(stack.top() == '{' && s[i] == '}'){
                    stack.pop();
                    continue;
                }
                stack.push(s[i]);
                continue;
            }
        }
    return stack.empty()==true;
    }
};