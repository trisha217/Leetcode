class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {

        int carry = 0;

        vector<int> kv;
        while(k>0){
            kv.push_back(k%10);
            k/=10;
        }

        reverse(num.begin(), num.end());

        vector<int> ans;

        int i=0, j=0;
        while(i<kv.size() || j<num.size())
        {
            int a = i < kv.size() ? kv[i++] : 0;
            int b = j < num.size() ? num[j++] : 0; 

            int n1 = a+b+carry;
            carry = n1/10;
            ans.push_back(n1%10);
        }

        if (carry)
        ans.push_back(carry);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};