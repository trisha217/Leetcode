class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left,ans;
        int product=1;
        int n=nums.size(); 
        vector<int> right(n,0);
        for(int i=0;i<n;i++)
        {
            left.push_back(product);
            product *= nums[i];
        }
        for(int i=0;i<left.size();i++)
        {
            cout<<left[i]<<" ";
        }
        cout<<endl;
        product =1;
        for(int i=n-1;i>=0;i--)
        {
            right[i] = product;
            product *= nums[i];
        }
        for(int i=0;i<right.size();i++)
        {
            cout<<right[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            ans.push_back(left[i] * right[i]);
        }
        return ans;
    }
};