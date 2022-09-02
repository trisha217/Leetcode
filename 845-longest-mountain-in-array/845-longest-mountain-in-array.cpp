class Solution {
public:
     int longestMountain(vector<int>& arr) {
        int n=arr.size();
        if(n==1){
            return 0;
        }
        int ans=0;
        vector<int>lis(n,1);
        vector<int>lds(n,1);
        //for lis
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                lis[i]=lis[i-1]+1;
            }
        }
        //for lds
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                lds[i]=lds[i+1]+1;
            }
        }
        // cout<<"LIS "<<endl;
        // for(auto it:lis){
        //     cout<<it<<" ";
        // }
        //  cout<<"LDS "<<endl;
        // for(auto it:lds){
        //     cout<<it<<" ";
        // }
        for(int i=1;i<n-1;i++){
            if(lis[i]==1||lds[i]==1){
                continue;
            }
            int temp=abs(lis[i]+lds[i]-1);
            ans=max(ans,temp);
        }
        return ans==1?0:ans;
    }
};
