class Solution {
public:
    bool check(vector<int>&v,int m,int dist)
    {
        int cnt=0;
        int last;
        for(int i=0;i<v.size();i++)
        {
            if(i==0)
            {
                last=v[0];
                cnt++;
            }
            else
            {
                if(v[i]-last>=dist)
                {
                    last=v[i];
                    cnt++;
                }
            }
        }
        return cnt>=m;
    }
    int maxDistance(vector<int>& position, int m) 
    {
        int low=1;
        int high=1e9;
        int ans=1;
        sort(position.begin(),position.end());
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(position,m,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }  
        }
        return ans;
    }
};