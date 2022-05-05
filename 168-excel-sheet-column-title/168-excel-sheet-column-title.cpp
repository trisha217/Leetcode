class Solution {
public:
    string convertToTitle(int col) {
        string s="";
        while(col){
            col--;
            int d = col%26;
            s+=('A'+d);
            col=col/26;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};