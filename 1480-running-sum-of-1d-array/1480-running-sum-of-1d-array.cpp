//Solution 02:
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        
        for(int i=1; i<=nums.size(); i++)
            ans.push_back(accumulate(nums.begin(), (nums.begin()+i), 0));
        
        return ans;
    }
};

/*Using STL function
It takes 3 parameters: first, last &sum.
Time complexity: O(n×k), where n is the distance from first to last, O(k) is the complexity of the function.
*/