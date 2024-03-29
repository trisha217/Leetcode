class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long n = nums.size();
        long long count = 0;
        long long subArray = 0; 
        
        for(int i = 0; i< n; i++)
        {
            if(nums[i] == 0)
            {
                count++;
            } 
            else
            {
                subArray = subArray + count*(count+1)/2;
                count=0;
            }
        }  
        subArray = subArray + count*(count+1)/2;
        return subArray;
    }
};