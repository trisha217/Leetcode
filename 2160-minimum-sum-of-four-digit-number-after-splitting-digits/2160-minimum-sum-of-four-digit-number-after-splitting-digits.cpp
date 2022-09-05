class Solution {
public:
    int minimumSum(int num) {
        vector<int> dig(4);
        for (int i = 0; i < 4; ++i, num /= 10) 
            dig[i] = num % 10;
        sort(dig.begin(),dig.end());
        return (10 * (dig[0] + dig[1])) + dig[2] + dig[3];
    }
};