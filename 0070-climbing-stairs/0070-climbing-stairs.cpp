class Solution {
public:
    int climbStairs(int n) {
        if(n<=2){
            return n;
        }
        //vector<int> dp(n+1,-1);
        int prev = 2;
        int prev2 = 1;
        int curr;
        for(int i=3;i<=n;i++){
            curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};