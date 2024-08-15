class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int store5 = 0;
        int store10 = 0;
        int n= bills.size();
        if(bills[0]>5){
            return false;
        }
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                // If the customer pays with $5, increase the $5 count
                store5++;
            }
            else if(bills[i]==10){
                if(store5 > 0) {
                    store5--;  // Use one $5 bill
                    store10++; // Gain one $10 bill
                } 
                else {
                    return false; // Can't provide change
                }   
            }
            else if(bills[i]==20){
                if(store10 > 0 && store5 > 0) {
                    store10--; // Use one $10 bill
                    store5--;  // Use one $5 bill
                } 
                else if(store5 >= 3) {
                    // If no $10 bill, give change using three $5 bills
                    store5 -= 3;
                } 
                else {
                    return false; // Can't provide change
                }
            }
        }
        return true;
    }
};