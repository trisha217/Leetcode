class Solution {
public:

    bool possible(vector<int> &arr, int mid, int m, int k){
        int cnt=0;
        int ans=0;
        int n=arr.size();

        for(int i=0;i<n;i++){
            if(arr[i]<=mid){
                cnt++;
            }
            else{
                ans+=(cnt/k);
                cnt=0;
            }
        }
        ans+=(cnt/k);
        return ans>=m;
    }
    int minDays(vector<int>& arr, int m, int k) {
        long long val = m * 1ll * k * 1ll;
        int n=arr.size();

        if(val>n){
            return -1;
        }

        int low = *min_element(arr.begin(), arr.end());
        int high= *max_element(arr.begin(), arr.end());
        while(low<=high){
            int mid = (low+high)/2;

            if(possible(arr, mid, m ,k)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};