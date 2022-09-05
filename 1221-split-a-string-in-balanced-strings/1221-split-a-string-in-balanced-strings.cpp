class Solution {
public:
    int balancedStringSplit(string s) {
        int rc=0,lc=0,c=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == 'R'){
                rc++;
            }
            else if(s[i] == 'L'){
                lc++;
            }
            if(rc==lc){
                c++;
            }
        }
        return c;
    }
};


//RL  RRRLLRLL              //RL RRLL RL RL

//11  23423545              //11 2323 44 55