class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> dp(n,1);
        vector<int> hash(n,1);
        for(int ind=0; ind<=n-1; ind++){
            hash[ind] = ind; 
            for(int prev_index = 0; prev_index <=ind-1; prev_index ++){
                if(arr[ind]%arr[prev_index] == 0 && 1 + dp[prev_index] > dp[ind]){
                    dp[ind] = 1 + dp[prev_index];
                    hash[ind] = prev_index;
                }
            }
        }
        int ans = -1;
        int lastIndex =-1; 
        for(int i=0; i<=n-1; i++){
            if(dp[i]> ans){
                ans = dp[i];
                lastIndex = i;
            }
        }
        vector<int> temp;
        temp.push_back(arr[lastIndex]);
        while(hash[lastIndex] != lastIndex){ // till not reach the initialization value
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);    
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};