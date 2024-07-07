class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty=numBottles;
        int ans=numBottles;
        int p=0;
        while(empty/numExchange>=1){
            p=empty/numExchange;
            ans+=p;
            empty=empty%numExchange;
            empty=empty+p;
        }
        return ans;
    }
};