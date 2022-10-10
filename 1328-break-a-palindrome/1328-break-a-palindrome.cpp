class Solution {
public:
    string breakPalindrome(string palindrome) {
        string ans = "";
        if(palindrome.size()==1){
            return ans;
        }
        int n = palindrome.size();
        for(int i=0;i<n/2;i++){
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                return palindrome;
            }
        }
        palindrome[n-1]='b';
        return palindrome;
    }
};