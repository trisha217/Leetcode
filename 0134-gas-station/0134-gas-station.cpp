class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int x=0;
        int count=-1;
        int str=0;
        int k=0;
        for(int i=0;i<gas.size();i++){
           x=x+gas[i]-cost[i];
        }
        for(int i=0;i<gas.size()-1;i++){
            k=k+gas[i]-cost[i];
            if(k<0){
                str=i+1;
                k=0;
            }
        }
        if(x>=0){
            return str;
        }
        return count;
    }
};