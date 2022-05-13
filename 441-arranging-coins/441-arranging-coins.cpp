class Solution {
public:
    int arrangeCoins(int n) {
        int c =0;
        int i=1;
        while(n>=0){
            n = n-i;
            //cout<<"n"<<n<<endl;
            c=c+1;
            //cout<<"c"<<c<<endl;
            i=i+1;
            //cout<<"i"<<i<<endl;
        }
         if(n<0){
                c=c-1;
            }
        return c;
    }
};