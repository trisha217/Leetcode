class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int p,i,j;
        vector<int> ans;
        for(i =0;i<num.size();i++){
            p=target-num[i];
            ans.push_back(i);
            for(j=i+1;j<num.size();j++){
                if(p==num[j])
                {
                   ans.push_back(j); 
                   return ans;
                }
            }
            ans.pop_back();
        }
        return ans;
    }
};