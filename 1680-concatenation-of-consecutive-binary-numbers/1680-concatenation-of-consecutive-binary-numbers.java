class Solution {
    public int concatenatedBinary(int n) {
        int mod = 1000000007, Lshift =0;
        long ans = 0;
        for(int i=1;i<=n;i++){
            if ((i & (i - 1)) == 0) {
                 Lshift= Lshift + 1;
            }
            ans = ((ans << Lshift) | i) % mod;
        }
        return (int)ans;
    }
}