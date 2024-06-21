class Solution {
public:
    int maxSatisfied(vector<int>& cus, vector<int>& grm, int min) {
        int ans=0;
        int n=cus.size();
        int l=0,h=0,maxi=0,sum=0,cnt=0;
        while(l<n){
            if(l-h+1<=min){
                if(grm[l]==0) ans+=cus[l];
                else sum+=cus[l];
                l++;
            }
            else{
                maxi=max(maxi,sum);
                if(grm[h]==1) sum-=cus[h];
                h++;
            }
           
        }
        maxi=max(maxi,sum);
        return ans+maxi;

    }
};