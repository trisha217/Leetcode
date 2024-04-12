class Solution {
public:
    bool check(string &a, string &b){
        int m = a.size();
        int n = b.size();
        if(m!=n+1){
            return false;
        }
        int first =0;
        int second =0;
        while(first<m){
            if(a[first]==b[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        if(first == m && second ==n){
            return true;
        }
        return false;
    }

    bool static comp(string& s1, string& s2){
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string> &arr){
        int n=arr.size();
        sort(arr.begin(),arr.end(),comp);
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(arr[i],arr[j])){
                    dp[i] = max(1+dp[j],dp[i]);
                }
            }
            if(dp[i]>maxi){
                maxi = max(maxi,dp[i]);
            }
        }
        return maxi;
    }
};

