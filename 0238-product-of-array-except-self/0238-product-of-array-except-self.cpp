class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n,1);
        vector<int> suf(n,1);
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] * nums[i-1];
        }
        for(int j=n-2;j>=0;j--){
            suf[j] = suf[j+1] * nums[j+1];
        }
        for(int i=0;i<n;i++){
            pre[i] = pre[i] *suf[i];
        }
        return pre;
    }
};