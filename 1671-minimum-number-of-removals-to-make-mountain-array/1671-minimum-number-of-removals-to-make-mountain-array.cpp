class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n,1);
        vector<int> lds(n,1);
        vector<int> bitonic(n);
        //int maxi1=1;
        for(int ind=0;ind<=n-1;ind++){
            for(int prev =0;prev<=ind-1;prev++){
                if(nums[prev]<nums[ind] && lis[ind]<1+lis[prev]){
                    lis[ind] =1 +lis[prev];
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
                if(nums[prev]<nums[ind] && lds[ind]<1+lds[prev]){
                    lds[ind] =1 + lds[prev];
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<dp2[i]; 
        // }
        // cout<<endl;
        int ans =1;
        for(int i=0;i<n;i++){
            if(lis[i]==1 || lds[i]==1){
                continue;
            }
            bitonic[i] = lis[i] + lds[i] -1;
            ans = max(ans,bitonic[i]);  
        }
        //cout<<ans<<endl;
        return nums.size()-ans;
    }
};