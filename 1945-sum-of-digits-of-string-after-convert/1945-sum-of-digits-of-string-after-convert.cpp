class Solution {
public:
    int sumOfDigits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int getLucky(string s, int k) {
        string f= "";
       for(char ch: s){
           int n = ch - 'a'+1;
           f.append(to_string(n));
           //cout<<n;
       }
        int j = 0;
        for (char ch : f) {
            j += ch - '0';
        }
        while(k>1){
            j = sumOfDigits(j);
            k--;
        }
        return j;
    }
};