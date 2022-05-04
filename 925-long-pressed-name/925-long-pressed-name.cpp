class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0,j=0;
        int len1=name.size();
        int len2 = typed.size();
        while(i<len1 && j<len2){
            if(name[i]==typed[j]){
                i++;
                j++;
            }
            else if(i>0 && name[i-1]==typed[j]){
                j++;
            }
            else{
                return false;
            }
        }
        while(j<len2){
            if(name[i-1]!=typed[j]){
                return false;
            }
            j++;
        }
        if(i<len1 && j>=len2){
            return false;
        }
        return true;
    }
};