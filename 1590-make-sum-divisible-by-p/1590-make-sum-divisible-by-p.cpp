
class Solution 
{
public:
    int minSubarray(vector<int>& nums, int p) 
    {
        int n = nums.size();
        long long sum=0;
        for(auto t:nums) sum+=t;
        if(sum%p==0) return 0;
        int rem=sum%p;
        unordered_map<int,int> mp;
        mp[0]=-1;
        int ans=n;
        long long prefixsum=0;
        for(int i=0;i<n;i++)
        {
            prefixsum+=nums[i];
            int remmod=prefixsum%p;
            int target=(remmod-rem+p)%p;
            if(mp.find(target)!=mp.end())
            {
                ans=min(ans,i-mp[target]);
            }
            mp[remmod]=i;
        }
        return ans==n ? -1:ans;
    }
};