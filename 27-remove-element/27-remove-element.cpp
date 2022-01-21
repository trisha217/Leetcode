class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                nums[i]=99;   
            }
        }
        sort(nums.begin(),nums.end());
        for(int i =0;i<nums.size();i++){
            if(nums[i]==99){
                return i;  
            }
        }
        return nums.size();
    }
};