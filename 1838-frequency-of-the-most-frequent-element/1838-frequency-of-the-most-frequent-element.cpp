class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        long int left=0,right=0,sum=0,maxx=0,n=nums.size();
        for(right = 0 ; right < n ; right++)
        {
            sum += nums[right];
            if(  nums[right]*(right-left+1) > sum+k)
            {
                sum -= nums[left];
                left++;
            }
            maxx=max(maxx,(right- left+1));
        }
        return maxx;
    }
};