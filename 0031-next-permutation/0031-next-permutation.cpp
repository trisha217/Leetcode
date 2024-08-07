class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n=arr.size();
        next_permutation(arr.begin(),arr.end());
        //using in-built function of C++
        for(int i=0;i<n;i++){
            cout<<arr[i];
        }
        return;
    }
};