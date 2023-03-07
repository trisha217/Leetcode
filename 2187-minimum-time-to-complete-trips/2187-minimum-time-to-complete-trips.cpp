class Solution {
public:
    #define ll long long 

    bool isPossible(vector<int>&time, int totalTrips, ll mid){
        ll count = 0;
        for(int i=0;i<time.size();i++){
            count+=(ll)(mid/time[i]);
        }

        if(count >= (ll)totalTrips)
            return true;
        return false;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        ll high = (ll)time[0] * (ll)totalTrips;
        ll low = 1;

        ll res = high;

        while(low <= high){
            ll mid = low + (high - low)/2;
            if(isPossible(time, totalTrips, mid)){
                res = min(res, mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return res;
    }
};