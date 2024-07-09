class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double time = customers[0][1];
        double start = customers[0][0];
        for(int i=0;i<n-1;i++){
            start = start + customers[i][1];
            if(start > customers[i+1][0]){
                time = time + start + (customers[i+1][1]-customers[i+1][0]);
            }
            else{
                time = time + customers[i+1][1];
                start = customers[i+1][0];
            }
        }
        return time/n;
    }
};