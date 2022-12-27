class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int addi) {
        int s = rocks.size();
        int ans =0;
        vector<int> diff;
        for(int i =0;i<s;i++){
            diff.push_back(capacity[i]-rocks[i]);
        }
        sort(diff.begin(),diff.end());
         for(int j=0;j<s;j++)
        {
            if(addi>=diff[j])
            {
                  addi=addi-diff[j];
                  diff[j]=0;
            }
        }
        for(int i=0;i<s;i++)
        {
            if(diff[i]==0)
                ans++;
        }
        return ans;
    }
};