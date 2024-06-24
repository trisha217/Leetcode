class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int ans = 0, n = nums.size();
        vector<int> count(n + 1, 0);
        int sum = 0;
        for (int i = 0; i <= n - k; i++)
        {
            sum += count[i];
            if ((nums[i] + sum) % 2 == 0)
            {
                count[i]++;
                sum++;
                count[i + k]--;
                ans++;
            }
        }
        for (int i = n - k + 1; i < n; i++)
        {
            sum += count[i];
            if ((nums[i] + sum) % 2 == 0)
            {
                return -1;
            }
        }
        return ans;
    }
};