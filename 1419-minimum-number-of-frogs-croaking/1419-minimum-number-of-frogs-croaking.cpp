class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int frog =0;
        int ans = -1;
        int n = croakOfFrogs.size();
        int c=0,r=0,o=0,a=0,k=0;
        for(int i=0;i<n;i++){
            if(croakOfFrogs[i]=='c'){
                frog++;
                c++;
            }
            if(croakOfFrogs[i]=='r'){
                r++;
            }
            if(croakOfFrogs[i]=='o'){
                o++;
            }
            if(croakOfFrogs[i]=='a'){
                a++;
            }
            if(croakOfFrogs[i]=='k'){
                k++;
                frog--;
            }
            ans = max(ans,frog);
            if(c<r || r<o || o<a || a<k){
                return -1;
            }
        }
        if(frog!=0){
                return -1;
        }
        return ans;
    }
};