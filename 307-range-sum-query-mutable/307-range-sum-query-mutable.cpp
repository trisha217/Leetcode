class NumArray {
    vector<int> arr; //Initialising global array
    int sum = 0; // Initialising global sum
public:
    NumArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
            arr.push_back(nums[i]), sum+=nums[i]; // storing elements in global array and calculating sum of elements - O(N)
    }
    
    void update(int index, int val) {
        sum += val - arr[index]; // Updating global sum with new value - O(1)
        arr[index] = val; // Updating the val at index in global array - O(1)
    }
    
    int sumRange(int left, int right) {
        int res = 0;
        if(right-left<arr.size()/2) {
            res = accumulate(arr.begin()+left, arr.begin()+right+1, 0); //If range(left, right) is less than half of array length, then calculating sum from left to right - O(<N/2) [Precise]
        } else {
            res = sum - accumulate(arr.begin(), arr.begin()+left, 0) - accumulate(arr.begin()+right+1, arr.end(), 0); // /If range(left, right) is greater than half of array length, then calculating sumRange by subtracting sum from 0th index to left-1 and from right+1 to last index from the global sum.
			//i.e. sum - sum(0, left-1) - sum(right+1, n-1) where n is length of array
        }
        return res;
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */