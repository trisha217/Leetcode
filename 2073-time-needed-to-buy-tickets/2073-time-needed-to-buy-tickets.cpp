class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int time =0;
        int i=0;
        while(tickets[k]!=0 && i<n){
            if(tickets[i]>0){
                tickets[i]--;
                time++;
            }
            i++;
            if(i==n){
                i=0;
            }    
        }
        return time;
    }
};