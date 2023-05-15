class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        // LIS must ending with ith element
        // since we have time constraint -> use binary search method to find LIS

        vector<int> ans,LIS;

        for(auto it: obstacles) {
            //index of next greater element than it
            int index = upper_bound(LIS.begin(),LIS.end(),it) - LIS.begin();
            if(index==LIS.size()) LIS.push_back(it);
            else LIS[index]=it;

            ans.push_back(index+1);
        }

        return ans;
    }
};