class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>ans(k+1,0);
        //calculate all remainders
        for(int i=0;i<arr.size();i++){
            int rem=(arr[i]%k);
            //handling negative arr[i] for remainders
            rem=(arr[i]%k+k)%k;
            ans[rem]++;
        }
        // for(auto&it:ans){
        //     cout<<it<<" ";
        // }
        cout<<endl;
        //check if all have
        if(ans[0]%2!=0){
            return false;
        }
        for(int i=1;i<=k/2;i++){
            // int rem=(arr[i]%k+k)%k;
            // cout<<i<<" "<<k<<endl;
            if(ans[i]!=ans[k-i]){
                return false;
            }
        }
        return true;
    }
};