class Solution {
public:
    static bool comp(const vector<int>& vec1, const vector<int>& vec2)
    {
        return vec1[1] > vec2[1];
    }
    int maximumUnits(vector<vector<int>>& vec, int truckSize) {
        sort(vec.begin(), vec.end(), comp);
        int ans=0;
        for(auto&it:vec){
                if(it[0]<=truckSize){
                    ans =ans + (it[0]*it[1]);
                    truckSize=truckSize-it[0];
                }
                else
                {
                    ans = ans + (truckSize*it[1]);
                    break;
                }
        }
        return ans;
    }
};