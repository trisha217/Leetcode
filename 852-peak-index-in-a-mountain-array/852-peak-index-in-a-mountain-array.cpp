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

//O(log n) time complexity
// int peakIndexInMountainArray(vector<int>& arr) {
//         int low = 0, high = arr.size()-1;
//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             if (arr[mid] < arr[mid+1])
//                 low = mid+1;
//             else
//                 high = mid-1;
//         }
//         return low;
//     }