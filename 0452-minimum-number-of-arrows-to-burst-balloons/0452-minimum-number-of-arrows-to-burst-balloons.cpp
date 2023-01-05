class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count=0;
        sort(points.begin(),points.end());
        vector<int> tempInterval = points[0];
        for(auto it:points){
            if(it[0]<=tempInterval[1]){
                tempInterval[1]=min(it[1],tempInterval[1]);
            }
            else{
                count++;
                tempInterval = it;
            }
        }
        count++;
        return count;
    }
};