class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        vector<int> temp;
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(temp.empty() || arr[i]>temp.back()){
                temp.push_back(arr[i]);
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
                temp[ind]=arr[i];
            }
        }
        return temp.size();
    }
};