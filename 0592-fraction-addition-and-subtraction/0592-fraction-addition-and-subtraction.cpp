#include <numeric>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdlib>

class Solution {
public:
    int gcd(int a, int b) {
        return std::gcd(a, b); 
    }

    string fractionAddition(string s) {
        int n = s.size();
        long long numerator = 0;
        long long denominator = 1;
        int i = 0;

        while (i < n) {
            long long sign = 1;
            if (s[i] == '+' || s[i] == '-') {
                sign = (s[i] == '-') ? -1 : 1;
                i++;
            }

            long long num = 0;
            while (i < n && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }

            i++; 
            long long denom = 0;
            while (i < n && isdigit(s[i])) {
                denom = denom * 10 + (s[i] - '0');
                i++;
            }

            numerator = numerator * denom + sign * num * denominator;
            denominator = denominator * denom;

            long long commonDivisor = gcd(abs(numerator), denominator);
            numerator /= commonDivisor;
            denominator /= commonDivisor;
        }

        return to_string(numerator) + "/" + to_string(denominator);
    }
};
