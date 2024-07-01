class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cntOdd=0;
        for(int i=0;i<arr.size();i++){
            // Increase the cntOdd if the number is odd,
            // else reset the cntOdd
            if(arr[i]&1)
                cntOdd++;
            else
                cntOdd=0;

            // Check if there are three consecutive odd numbers
            if(cntOdd==3)
                return true;
        }
        return false;
    }
};