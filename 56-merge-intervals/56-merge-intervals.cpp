class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size()==0){
            return ans;
        }
        sort(intervals.begin(),intervals.end());
        vector<int> tmpInterval = intervals[0];
        //the first interval of length 2 is stored in tmpInterval
        for(auto it : intervals){
            if(it[0]<=tmpInterval[1]){
                tmpInterval[1]=max(it[1],tmpInterval[1]);
            }
            else{
                ans.push_back(tmpInterval);
                tmpInterval = it;
            }
        }
        ans.push_back(tmpInterval);
        return ans;
    }
};