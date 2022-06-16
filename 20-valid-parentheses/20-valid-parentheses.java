class Solution {
    public boolean isValid(String s) {
        int n = s.length();
        Stack<Character> st = new Stack<>();
        for(int i=0;i<n;i++){
            char ch = s.charAt(i);
            if((ch == ')' || ch == ']' || ch == '}') && st.empty()){
                return false;
            }
            else if(ch == ')' || ch == ']' || ch == '}'){
                if(st.peek()== '(' && ch ==')'){
                    st.pop();
                }
                else if(st.peek()== '{' && ch =='}'){
                    st.pop();
                }
                else if(st.peek()== '[' && ch ==']'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(ch=='(' || ch=='{' || ch=='['){
                st.push(s.charAt(i));
            }
        }
        if(!st.empty()){
            return false;
        }
        else{
            return true;
        }
    }
}