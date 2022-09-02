class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n= arr.size();
        int p=1;
        while(p<n){
            if(arr[p-1]<arr[p]){
                p++;
            }
            else{
                break;
            }
        }
        return p-1;
    }
};