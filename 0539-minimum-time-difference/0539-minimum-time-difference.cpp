class Solution {
private:
    int timeToMinute(const string& time) {
        // first convert the time into minutes
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3, 2));
        
        return hours * 60 + minutes; // we got the minutes from the time
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        
        vector<int> result;
        for(const string& time : timePoints) {
            // converted the string into minutes
            result.push_back(timeToMinute(time));
        }
        
        sort(result.begin(), result.end());

        int minTime = INT_MAX;
        for(int i = 0; i < result.size() - 1; ++i) {
            int remTime = abs(result[i] - result[i + 1]);
            minTime = min(minTime, remTime);
        }

        int wrapTime = 1440 + result[0] - result.back();

        return min(minTime, wrapTime);
    }
};