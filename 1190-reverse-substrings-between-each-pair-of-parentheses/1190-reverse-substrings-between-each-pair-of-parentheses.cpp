class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> mystack;
        for(char c : s) {
            if(c == ')') {
                func(mystack);
            } else {
                mystack.push(c);
            }
        }
        string res = "";
        while(!mystack.empty()) {
            res += mystack.top();
            mystack.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

    void func(stack<char> &myStack) {
        string t = "";
        while(!myStack.empty() && myStack.top() != '(') {
            t += myStack.top();
            myStack.pop();
        }
        if(!myStack.empty())
            myStack.pop();
        for(char c : t)
            myStack.push(c);
    }
};