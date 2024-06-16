class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long k=1;
        int i=0;
        int count=0;

        while(k<=n){
            if(i<nums.size() && nums[i]<=k){
                k+=nums[i];
                i++;
            }
            else{
                k+=k;
                count++;
            }
        }
        return count;
    }
};