class MinStack {
public:
    stack<int> s;
    stack<int> mint;
    
    
    void push(int val) {
        s.push(val);
        if(mint.empty() or s.top() <= mint.top())
            mint.push(val);
    }
    
    void pop() {
         if(s.empty())
            return;
        
        int temp = s.top();   
        s.pop();
        if(temp == mint.top())
            mint.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
         if(mint.empty())
            return -1;
        return mint.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */