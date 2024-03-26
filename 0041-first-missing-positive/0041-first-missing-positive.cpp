class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            if(nums[i]==i+1)i++;
            else if(nums[i]>=1 && nums[i]<=nums.size()){
                if(nums[i]==nums[nums[i]-1])i++; // checks for
                //duplicate of the number at correct position
                else(swap(nums[i],nums[nums[i]-1]));
            }
            else i++;
        }
        for(int i=0;i<nums.size();i++){
            if (nums[i]!=i+1){
                return i+1;
            }
        }
    return nums.size()+1;
    }
};