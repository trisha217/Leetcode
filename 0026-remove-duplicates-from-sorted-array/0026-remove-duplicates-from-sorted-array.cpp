class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=1;
        int n=nums.size();
        if(n==0){
            return 0;
        }
        while(j<n){
            if(nums[i]==nums[j]){
                j++;
            }
            else if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        }
        //cout<<i+1;
        return i+1;
    }
};