class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n,1);
        vector<int> dp2(n,1);
        vector<int> bitonic(n);
        //int maxi1=1;
        for(int ind=0;ind<=n-1;ind++){
            for(int prev =0;prev<=ind-1;prev++){
                if(nums[prev]<nums[ind] && dp1[ind]<1+dp1[prev]){
                    dp1[ind] =1 +dp1[prev];
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<dp1[i]; 
        // }
        // cout<<endl;
        //int maxi2=1;
        for(int ind=n-1;ind>=0;ind--){
            for(int prev =n-1;prev>ind;prev--){
                if(nums[prev]<nums[ind] && dp2[ind]<1+dp2[prev]){
                    dp2[ind] =1 + dp2[prev];
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<dp2[i]; 
        // }
        // cout<<endl;
        int ans =1;
        for(int i=0;i<n;i++){
            if(dp1[i]==1 || dp2[i]==1){
                continue;
            }
            bitonic[i] = dp1[i] + dp2[i] -1;
            ans = max(ans,bitonic[i]);  
        }
        //cout<<ans<<endl;
        return nums.size()-ans;
	    // int maxi=INT_MIN;
	    // for(int i=0;i<n;i++){
	    // if(dp1[i]==1 or dp2[i]==1)
	    // continue;
	    //     maxi=max(maxi,dp1[i]+dp2[i]-1);
	    // }
	    // return nums.size()-maxi;
    }
};