class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        //to be a mountain array, min size should be 3
        if(n<3){
            return false;
        }
        //now we gotta check and find the peak element if the array is increasing till a point, can do that using a pointer
        int p =1;
        while(p<n){
            if(arr[p-1]<arr[p]){
                p++;
            }
            else{
                break;
            }
        }
        //if first element is the largest element then the array is strictl increasing and hence cannot be a mountain array
        //or else the mountain array 
        if(p==1 || p==n){
            return false;
        }
        while(p<n){
            if(arr[p-1]>arr[p]){
                p++;
            }
            else{
                break;
            }
        }
        if(p==n) 
            return true;
	    else 
            return false;
    }
};