class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            if(nums[0]==1){
                return 0;
            }
            else{
                return 1;
            }
        }
        int flag =0;
        int ans;
        sort(nums.begin(),nums.end());
        if(nums[0]!=0){
            return 0;
        }
        for(int i=0;i<n-1;i++){
            if(nums[i]+1 == nums[i+1]){
                
            }
            else{
                flag =1;
                ans = nums[i]+1;
            }
        }
        if(flag ==1)
            return ans;
        else 
            return n;
    }
};