class Solution {
public:
    vector<int> nextgreater(vector<int> &nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = n-1; i>=0; i--){
           while(!st.empty() && st.top() < nums[i]) st.pop();
           ans[i] = st.empty() ? -1 : st.top();
           st.push(nums[i]);
        }
        return ans;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ngr = nextgreater(nums2);
        unordered_map<int, int>mp;
        for(int i = 0; i<nums2.size(); i++){
            mp[nums2[i]] = ngr[i];
        }
        int n = nums1.size();
        vector<int> ans(n);
        for(int i = 0; i<nums1.size(); i++){
            ans[i] = mp[nums1[i]];
        }
        return ans;
    }
};