class Solution {
public:
    
    void swap(vector<int>& nums,int a, int b)
    {
        int temp = nums[a];
        nums[a]=nums[b];
        nums[b]=temp;
    }
    void sortColors(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int k=j;
        while(i<=j){
            int curr = nums[j];
            if(curr ==0){
                swap(nums,i,j);
                i++;
            }
            else if(curr==2){
                swap(nums,j,k);
                j--;
                k--;
            }
            else{
                j--;
            }
        }
        
    }
};