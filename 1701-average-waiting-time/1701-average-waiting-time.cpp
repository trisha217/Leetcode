class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double ans = 0;
        int kab_aya = 0;
        int kab_gaya =0;
        int start_time = 0;
        bool chef_free=true;
        for(int i=0;i<n;i++){
            kab_aya = customers[i][0];
            //1
            if(kab_gaya>kab_aya){
                start_time = kab_gaya;
                //1
            }
            else{
                start_time = kab_aya;
            }
            kab_gaya = start_time + customers[i][1];
            //3
            ans = ans + (kab_gaya - kab_aya);
            //ans = 2
            cout<<endl<<"kab_aya"<<kab_aya<<"kab_gaya"<<kab_gaya<<"start_time"<<start_time<<"ans"<<ans;
        }
        return ans/n;
    }
};