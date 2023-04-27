class Solution {
public:
    int bulbSwitch(int n) {
        if (n == 0 || n == 1) return n;
        int i = 1, result = 1;

        // finding square root of the number n
        while (result <= n) {
            i++;
            result = (i * i);
        }
        return (i - 1);
    }
};