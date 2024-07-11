class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> mystack;
        for(char c : s) {
            if(c == ')') {
                func(mystack);
            } else {
                mystack.push(c);
                cout<<"push c "<<c<<endl;
            }
        }
        string res = "";
        while(!mystack.empty()) {
            res += mystack.top();
            mystack.pop();
            cout<<"res "<<res<<endl;
        }
        reverse(res.begin(), res.end());
        cout<<"res "<<res<<endl;
        return res;
    }

    void func(stack<char> &myStack) {
        string t = "";
        while(!myStack.empty() && myStack.top() != '(') {
            t += myStack.top();
            myStack.pop();
            cout<<"t "<<t<<endl;
        }
        //remove"(" from stack
        if(!myStack.empty())
            myStack.pop();
        for(char c : t){
            cout<<c<<endl;
            myStack.push(c);
        }
    }
};


//(u(love)i)
//(uevoli)
//iloveu