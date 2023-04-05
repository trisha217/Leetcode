class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long sums=0 , answer=0, ceiled=0;

        for(int i=0;i<nums.size();i++){
            sums += nums[i];
            ceiled= (long long) ceil(sums/(i+1.0));
            answer=max(answer,ceiled);
        }
        return answer;
    }
};