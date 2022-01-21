class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = duration;
        for(int i=1;i<timeSeries.size();i++)
        {
                int l = timeSeries[i-1];
                int r = timeSeries[i];
                int diff = r-l;
                int overlap;
                if(diff<duration){
                    overlap = duration - diff;
                    res = res - overlap;
                }
                res = res + duration;
            
        }
        return res;
    }
};