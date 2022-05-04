class Solution {
public:
    static bool comp(const vector<int>& vec1, const vector<int>& vec2)
    {
        return vec1[1] > vec2[1];
    }
    int maximumUnits(vector<vector<int>>& vec, int truckSize) {
        sort(vec.begin(), vec.end(), comp);
        // for(auto&it:vec){
        //     cout<<it[0]<<it[1]<<endl;
        // }
        int ans=0;
        int boxes=0;
        for(auto&it:vec){
                if(it[0]<=truckSize){
                    ans =ans + (it[0]*it[1]);
                    truckSize=truckSize-it[0];
                    //cout<<"ans"<<ans<<endl;
                    //cout<<"ts"<<truckSize<<endl;
                }
                else
                {
                    ans = ans + (truckSize*it[1]);
                    // cout<<"ans"<<ans<<endl;
                    // cout<<"ts"<<truckSize<<endl;
                    break;
                }
        }
        return ans;
    }
};