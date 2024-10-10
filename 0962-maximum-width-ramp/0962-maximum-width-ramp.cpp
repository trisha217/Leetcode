class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>vp(n);
        for(int i=0;i<n;++i)
        {
            vp[i]={nums[i],i+1};
        }
        sort(vp.begin(),vp.end());
        vector<int>maxi(n);
        maxi[n-1]=vp[n-1].second;
        for(int i=n-2;i>=0;--i)
        {
            maxi[i]=max(maxi[i+1],vp[i].second);
        }
        int maxx=0;
        for(int i=0;i<n;++i)
        {
            int y = maxi[i] - vp[i].second;
            maxx=max(maxx,y);
        }
        return maxx;
    }
};