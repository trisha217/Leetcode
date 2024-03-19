class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>d(26,0);
        for(auto &ch:tasks){
            d[ch-'A']++;
        }
        sort(d.begin(),d.end());
        int k=(d[25]-1)*n;
        int ans=k+d[25];
        for(int i=24;i>=0;i--){
            if(d[i]==d[25]){
                ans++;
                k++;
            }
            k-=d[i];
        }
        if(k<0)ans+=(-1*k);
        return ans;
    }
};