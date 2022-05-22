class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
     size_t n = cost.size();
        for(size_t i = 2; i < n; i++){
            cost[i] = min(cost[i-2], cost[i-1]) + cost[i];
        }
        return min(cost[n-2], cost[n-1]);
   
    }
};