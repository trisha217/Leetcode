class Solution {
public:
    int solve(vector<int>& nums) {
        int n = nums.size();
        //if (n == 0) return 0; 
        int cur, prev=nums[0], prev2=nums[0];
        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i>1)
                pick = pick + prev2;
            int notpick = 0 + prev;
            cur= max(pick,notpick);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        int n = nums.size();
        if (n == 1) return nums[0]; // Handle single element case
        for(int i=0;i<n;i++){
            if(i!=0){
                arr1.push_back(nums[i]);
            }
            if(i!=n-1){
                arr2.push_back(nums[i]);
            }
        }
        int ans1 = solve(arr1);
        int ans2 = solve(arr2);
        return max(ans1,ans2);
    }
};