class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0;
        int cnt2 = 0;  
        
        for (int i = 1; i < n; i++) {
            if (nums[i] >= nums[i-1]) {
                cnt1++;
            }
            
            if (nums[i] <= nums[i-1]) {
                cnt2++;
            }
        }
                
        return (n == cnt1 + 1 || n == cnt2 + 1);
    }
};


