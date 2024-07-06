class Solution {
public:
    int passThePillow(int n, int time) {
        if(time==0){
            return 1;
        }
        int chk=2*(n-1);
        time%=chk;
        if(time==0){
            return 1;
        }
        cout<<time<<endl;
        if(time>=(n-1)){
            if(time==n-1){
                return n;
            }
            int rem=time%(n-1);
            return n-rem;
        }
        return time+1;
    }
};