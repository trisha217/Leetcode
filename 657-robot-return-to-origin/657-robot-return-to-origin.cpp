class Solution {
public:
    bool judgeCircle(string s) {
        int n=s.size();
        int nu=0;
        int nd=0;
        int nl=0;
        int nr=0;
        for(int i=0;i<n;i++){
            if(s[i]=='U'){
                nu++;
            }
            if(s[i]=='D'){
                nd++;
            }
            if(s[i]=='L'){
                nl++;
            }
            if(s[i]=='R'){
                nr++;
            }
        }
        if(nu==nd && nr==nl){
            return true;
        }
        
        return false;
    }
};