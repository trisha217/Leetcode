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
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        int n= nums.size();
        return (n*(n+1))/2 - accumulate(nums.begin(),nums.end(),0);
    }
};