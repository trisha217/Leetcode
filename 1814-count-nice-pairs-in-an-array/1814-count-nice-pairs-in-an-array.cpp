class Solution {
public:
    int rev(int n){
        int sum=0;
        while(n!=0){
            int digit=n%10;
            sum=sum*10+digit;
            n=n/10;
        }
        return sum;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<long long,long long> mp;
        int mod=1e9+7;
        for(int i=0 ; i<nums.size() ; i++){
           int diff=nums[i]-rev(nums[i]);
           mp[diff]++;
        }
        
        int ans=0;
        for(auto &it : mp){
           int i=it.second;
           ans+=(((i)*1ll*(i-1))/2)%mod;
        }

        return ans%mod;
    }
};