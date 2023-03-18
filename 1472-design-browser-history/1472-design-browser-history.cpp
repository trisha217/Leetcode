class BrowserHistory {
    private:
    stack<string> history; 
    stack<string> future; 
 public:
  BrowserHistory(string homepage) {
    visit(homepage);
  }

  void visit(string url) {
    history.push(url);
    future = stack<string>(); // Clear the future stack
  }

  string back(int steps) {
    while (history.size() > 1 && steps-- > 0){
        string x=history.top();
        future.push(x);
        history.pop();
        //  future.push(history.top()), history.pop();   // short hand for the same
    }
    return history.top(); 
  }

  string forward(int steps) {
    while (!future.empty() && steps-- > 0){
         string x=future.top();
        history.push(x);
        future.pop();
     //   history.push(future.top()), future.pop(); 
    }
    return history.top(); 
  }
};