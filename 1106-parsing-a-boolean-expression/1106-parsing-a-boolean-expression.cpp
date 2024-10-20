class Solution {
public:
    bool orOper(stack<char>&s){
        bool ans = false;
        while(s.empty()==false && s.top()!=')'){
            char c = s.top();
            s.pop();
            if(c=='t') {return true;} 
        }
        return false;
    }
    bool andOper(stack<char>&s){
        bool ans = s.top()=='t'?true:false;
        s.pop();
        while(s.empty()==false && s.top()!=')'){
            char c = s.top();
            s.pop();
            if(c=='t') ans = ans && true;
            else ans = ans && false;
        }
        return ans;
    }
    bool notOper(stack<char>&s){
        if(s.empty()) return false;
        bool character = s.top()=='t'?true:false;
        s.pop();
        return (!character);
    }

    bool performOperation(char ch , stack<char>&s){
        switch (ch){
            case '|' : return orOper(s);
            case '&' : return andOper(s);
            case '!' : return notOper(s);  
        }
        return true;
    }


    bool parseBoolExpr(string expression) {
        stack<char>s;
        int n = expression.size();
        int j=n-1;
        for(j=n-1;j>=0;j--){
            char ch = expression[j];
            if(expression[j]==')' || expression[j]=='f' || expression[j]=='t')
            s.push(expression[j]);
            else if(ch=='(' || ch==',')
            continue;
            else
            {
                bool val = performOperation(ch,s);
                char topush = (val)?'t':'f';
                s.pop();
                s.push(topush);
            }
        }
        if(s.empty())return false;
        return s.top()=='t'?true:false;
    }
};