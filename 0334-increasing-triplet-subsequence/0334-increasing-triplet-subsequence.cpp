class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int k=INT_MAX, j=INT_MAX;
        int n=nums.size();
		
        for(int i=0;i<n;i++){
            if(nums[i]<=k)
                k=nums[i];
				
            else if(nums[i]<=j)
                j=nums[i];
				
            else {
                return true;
            } 
        }
        return false;
    }
};