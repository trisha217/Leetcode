class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        stack<int> p;
        int c=0;
        for(auto j: s)
        {
            if(j=='(') p.push('(');
            else if(p.size() && p.top()=='(') p.pop();
            else c++;
        }
        return c+p.size();
    }
};