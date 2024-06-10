class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> arr = heights;
        int ans = 0;
        sort(heights.begin(),heights.end());
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=arr[i]) ans++;
        }
        return ans;
    }
};