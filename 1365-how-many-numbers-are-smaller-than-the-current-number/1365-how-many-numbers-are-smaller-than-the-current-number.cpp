class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int count;
        for(int i=0;i<n;i++){
            count =0;
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(nums[j]<nums[i]){
                        count++;
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};