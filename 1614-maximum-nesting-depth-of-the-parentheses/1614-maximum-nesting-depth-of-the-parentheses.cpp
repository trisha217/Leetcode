//just increment the count when you encounter ( and decrement the count when you encounter ) symbol and return the count

class Solution {
public:
    int maxDepth(string s) {
        //increase the count at insertion and decrease at deletion 
        int count=0,mx_count=0;
        for(auto x:s){
            if(x=='(')count++;
            else if(x==')'){
                mx_count=max(mx_count,count);
                count--;
            }
        }
        return mx_count;
    }
};