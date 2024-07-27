class Solution {
public:
    int getAns(vector<int>& arr) {
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
    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(),e.end(),[&](vector<int> &a, vector<int> &b)
        {
            if(a[0] == b[0])
            {
                return a[1] > b[1]; 
            }
            return a[0] < b[0];
        });
        vector<int> height;
        for(auto it : e)
        {
            height.push_back(it[1]);
        }
        return getAns(height);
    }
};