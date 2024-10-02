class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> arr1;
        vector<int> ans;
        arr1=arr;
        sort(arr1.begin(),arr1.end());
        unordered_map<int,int> nums;
        int rank=1;
        for(int i=0;i<arr1.size();i++)
        {
            if(i>0 && arr1[i]==arr1[i-1])
                continue;
            nums[arr1[i]]=rank;
            rank++;
        }
        for(int i=0;i<arr.size();i++)
            ans.push_back(nums[arr[i]]);
        return ans;
    }
};