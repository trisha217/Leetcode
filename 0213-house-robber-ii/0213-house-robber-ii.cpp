class Solution {
public:
    int solve(vector<int>& arr){
        int n = arr.size();
        int prev = arr[0];
        int prev2 =0;
    
        for(int i=1; i<n; i++){
            int pick = arr[i];
            if(i>1)
                pick += prev2;
            int nonPick = 0 + prev;
        
            int cur_i = max(pick, nonPick);
            prev2 = prev;
            prev= cur_i;
        
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        int n = nums.size();
        if(n==1)
            return nums[0];
    
        for(int i=0; i<n; i++){
        
            if(i!=0) arr1.push_back(nums[i]);
            if(i!=n-1) arr2.push_back(nums[i]);
        }
    
        int ans1 = solve(arr1);
        int ans2 = solve(arr2);
    
        return max(ans1,ans2);
    }
};