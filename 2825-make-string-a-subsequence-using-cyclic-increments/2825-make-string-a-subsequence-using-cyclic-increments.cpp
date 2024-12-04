class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int cnt=str2.size();
        int j=0;
        for(int i=0;i<str1.size() && j<str2.size();i++){
           if(str1[i]==str2[j]){
               j++;
           }else{
               char tem=str1[i];
               if(tem=='z') tem='a';
               else tem++;
               if(tem==str2[j]) j++;
           }
        }
        if(j>=cnt) return true;
        return false;
    }
};