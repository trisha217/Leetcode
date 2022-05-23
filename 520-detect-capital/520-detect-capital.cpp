class Solution {
public:
    bool detectCapitalUse(string s) {
        int n = s.length();
        int big = 0;
        int small = 0;
        int flagfirst =0;
        char char_array[n + 1];
        strcpy(char_array, s.c_str());
        for(int i=0;i<n;i++){
            if(isupper(char_array[i])){
                big++;
            }
            else{
                small++;
            }
        }
        cout<<big<<small;
        if(big == n || small == n){
            return true;
        }
        else if(isupper(char_array[0]) && small == n-1){
            return true;
        }
        else{
            return false;
        }
    }
};