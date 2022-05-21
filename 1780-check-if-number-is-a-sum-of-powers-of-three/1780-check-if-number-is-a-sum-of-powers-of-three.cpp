class Solution {
public:
    bool checkPowersOfThree(int n) {
        int no;
        for(int i=14;i>=0;i--){
            no = pow(3,i);
            if(n-no>=0){
                n = n-no;
            }
            if(n == 0){
                return true;
            }   
        }
        return false;
    }
};