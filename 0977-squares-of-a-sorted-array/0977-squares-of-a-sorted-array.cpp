class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        int k;
        for(k=0;k<n;k++){
            if(nums[k]>=0){
                break;
            }
        }
        int i = k-1;
        int j = k;
        while (i >= 0 && j < n){
            if(nums[i]*nums[i]<nums[j]*nums[j]){
                res.push_back(nums[i]*nums[i]);
                i--;
            }
            else{
                res.push_back(nums[j]*nums[j]);
                j++;
            }
        }
        /*Copy the remaining elements of first half */
        while (i >= 0) {
            res.push_back(nums[i]*nums[i]);
            i--;
        }

        /* Copy the remaining elements of second half */
        while (j < n) {
            res.push_back(nums[j]*nums[j]);
            j++;
        }
        return res;
    }
};