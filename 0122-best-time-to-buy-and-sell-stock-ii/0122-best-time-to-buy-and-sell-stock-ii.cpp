class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        int aheadbuy, aheadnotbuy, curbuy, curnotbuy;
        aheadnotbuy = aheadbuy = 0;

        // Loop through the array in reverse order
        for (int ind = n - 1; ind >= 0; ind--) {
            
            curnotbuy = max(a[ind] + aheadbuy,0 + aheadnotbuy );
            curbuy = max(-a[ind] + aheadnotbuy,0 + aheadbuy );
            
            
            aheadbuy = curbuy;
            aheadnotbuy = curnotbuy;
        }

        return aheadbuy;
    }
};