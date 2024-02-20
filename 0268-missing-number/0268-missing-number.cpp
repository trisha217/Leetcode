class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int n= nums.size();
        // for(int i=0;i<n;i++){
        //     if(i!=nums[i]){
        //         return i;
        //     }
        // }
        // return n;
        int n= nums.size();
        int sum = (n*(n+1))/2;
        return sum - accumulate(nums.begin(),nums.end(),0);
    }
};