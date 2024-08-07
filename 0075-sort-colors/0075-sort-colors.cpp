class Solution {
public:
    
    void swap(vector<int>& nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
    void sortColors(vector<int>& arr) {
        int low=0;
        int high=arr.size()-1;
        int mid =0;
        while(mid<=high){
            if(arr[mid]==2){
                swap(arr,mid,high);
                high--;
            }
            else if(arr[mid]==1){
                mid++;  
            }
            else{
                swap(arr,low, mid);
                low++;
                mid++;
            }
        }
        
    }
};