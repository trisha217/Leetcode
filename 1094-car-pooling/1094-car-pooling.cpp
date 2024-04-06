class Solution {
public:
    bool carPooling(vector<vector<int>>& trip, int capacity) {
        map<int,int> track;
        int n=trip.size();
        for(int i=0;i<n;i++){
            int enter = trip[i][1];
            int leave = trip[i][2];
            track[enter] = track[enter] + trip[i][0];
            track[leave] = track[leave] - trip[i][0];
        }
        int currCap = 0;
        for(auto it = track.begin();it!=track.end();it++){
            currCap = currCap + it->second;
            if(currCap > capacity){
                return false;
            }
        }
        return true;
    }
};