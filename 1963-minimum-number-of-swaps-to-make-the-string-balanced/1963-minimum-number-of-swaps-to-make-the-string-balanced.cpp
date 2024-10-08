class Solution {
public:
    int minSwaps(string s) {
        int op=0;
        for(auto x : s){
           if(x=='[')
           op++;
           else{
            if(op)op--;
           }
        }
        return (op+1)/2;
    }
};