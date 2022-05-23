class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ct=0;
        int res=start^goal;
        for(int i=31;i>=0;i--)
        {
            ct+=((res>>i)&1);
        }
        return ct;
    }
};