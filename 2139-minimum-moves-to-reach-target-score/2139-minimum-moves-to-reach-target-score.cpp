class Solution {
public:
    int minMoves(int target, int maxDouble) {
        if(maxDouble == 0){
            return target-1;
        }
        int ans = 0;
        while(target!=1 && maxDouble!=0){
            if(target%2 ==0){
                target = target/2;
                maxDouble--;
            }
            else{
                target = target -1;
            }
            ans++;
        }
        //cout<<"ans"<<ans<<endl;
        if(target>=1){
            ans = ans + (target-1);
        }
        return ans;
    }
};