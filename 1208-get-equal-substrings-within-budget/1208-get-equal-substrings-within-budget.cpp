class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.length();
        vector<int> v(n,0);
        v[0]=abs(t[0]-s[0]);

        for(int i=1;i<n;i++){
            v[i]=v[i-1]+abs(s[i]-t[i]);
        }   

        int i=0,j=0;
        int ans=0;
        while(i<n && j<n){
            int temp=i==0?v[j]:v[j]-v[i-1];
            if(temp<=maxCost){
                ans=max(ans,j-i+1);
                j++;
            }
            else i++;
        }
        return ans;
    }
};