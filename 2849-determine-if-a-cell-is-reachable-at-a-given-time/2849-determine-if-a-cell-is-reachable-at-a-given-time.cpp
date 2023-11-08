class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        if(sx == fx && sy == fy){
            if(t == 1){
                return false;
            }
            return true;
        }
        int mini = min(abs(fx - sx), abs(fy - sy));
        
        int ans = mini;
        int maxi = max(abs(fx - sx), abs(fy - sy));

        ans += maxi - mini;

        if(ans <= t){
            return true;
        }
        
        return false;
        
    }
};