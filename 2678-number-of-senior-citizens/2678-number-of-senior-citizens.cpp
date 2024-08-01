class Solution {
public:
    int countSeniors(vector<string>& details) {
        return count_if(details.begin(), details.end(), [](string& a) {
            return (10 * (a[11] - '0') + a[12] - '0') > 60;
        });
    }
};