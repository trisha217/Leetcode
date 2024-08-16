class Solution {
public:
    // int climbStairs(int n) {
    //     if(n==0){
    //         return 0;
    //     }
    //     if(n==1){
    //         return 1;
    //     }
    //     if(n==2){
    //         return 2;
    //     }
    //     return climbStairs(n-1) + climbStairs(n-2);
    // }
    int climbStairs(int n) {
        if(n<2){
            return 1;
        }
        int cur,prev=1,prev2=1;
        for(int i=2;i<=n;i++){
            cur = prev + prev2;
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};