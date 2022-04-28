class Solution {
public:
    bool rotateString(string s, string goal) {
        int len2=goal.size();
        int len1=s.size();
        int len3 = 0;
        int flag =0;
        if(len1<len2 || len2<len1){
            return false;
        }
        while(len3<=len2){
            for(int i=0;i<len1-1;i++){
                char temp = s[i];
                s[i]=s[i+1];
                s[i+1]=temp;
            }
            if(s==goal){
                flag=1;
                break;
            }
            len3++;
        }
        if(flag==1){
            return true;
        }
        else{
            return false;
        }
    }
};