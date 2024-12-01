class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        const int n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; ++i) {
            int a = lower_bound(arr.begin(), arr.end(), 2 * arr[i]) - arr.begin();
            if (a < n && a != i && arr[a] == 2 * arr[i]) {
                return true;
            }
        }
        return false;  
    }
};