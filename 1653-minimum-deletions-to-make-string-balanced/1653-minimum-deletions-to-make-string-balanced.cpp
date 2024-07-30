class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> aright(n,0);
        vector<int> bleft(n,0);
        int bcount = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                bcount++;
            }
            bleft[i] = bcount;
        }
        int acount=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a'){
                acount++;
            }
            aright[i] = acount;
        }
        // Calculate the minimum deletions
        int ans = min(bleft[n - 1], aright[0]); // All 'b's or all 'a's
        for (int i = 0; i < n - 1; ++i) {
            ans = min(ans, bleft[i] + aright[i + 1]);
        }
        // for(int i=0;i<n;i++){
        //     cout<<aright[i];
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<bleft[i];
        // }
        return ans;
    }
};