class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n1=0;
        int n2=0;
        int n0=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0){
                n0++;
            }
            else if(nums[i]==1){
                n1++;
            }
            else{
                n2++;
            }
        }
        //cout<<n0<<n1<<n2;
        int d1=0,d2=0,d0=0;
        for(int i=1;i<=nums.size();i++){
            if(d0<n0){
                nums[i-1]=0;
                d0++;
                cout<<"i printed 0"<<endl;
            }
            else if(d1<n1){
                nums[i-1]=1;
                d1++;
                cout<<"i printed 1"<<endl;
            }
            else if(d2<n2){
                nums[i-1]=2;
                d2++;
                cout<<"i printed 2"<<endl;
            }
            else{
                
            }
        }
    }
};