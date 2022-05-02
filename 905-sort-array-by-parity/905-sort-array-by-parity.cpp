class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int oddI=-1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0 && oddI!=-1){
                swap(nums[i],nums[oddI]);
                oddI++;
            }
            else if(nums[i]%2!=0 && oddI==-1)
            {
                oddI=i;
            }
        }   
        return nums;
    }
};