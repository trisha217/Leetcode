class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int left =0;
        int right = numbers.size()-1;
        while(left<right){
            int l = numbers[left];
            int r = numbers[right];
            if(l+r == target){
                ans.push_back(left+1);
                ans.push_back(right+1);
                break;
            }
            else if(l+r < target){
                left++;
            }
            else{
                right--;
            }
        }
        return ans;
    }
};