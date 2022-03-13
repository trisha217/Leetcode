class Solution {
public:
    int singleNumber(vector<int>& v) {
        int ans = v[0];
        for(int i=1;i<v.size();i++){
            ans= ans^v[i];
        }
        return ans;
    }
};