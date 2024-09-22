class Solution {
public:
    int findKthNumber(int n, int k) {
        long num=1;
        for(int i=1;i<k;){
            int req=getreq(num,num+1,n);
            if(i+req<=k){
                i+=req;
                num++;
            }else{
                i++;
                num*=10;
            }
        }return num;
    }
    private:
    int getreq(long a,long b,long n){
        int gap=0;
        while(a<=n){
            gap+=min(n+1,b)-a;
            a*=10;
            b*=10;
        }return gap;
    }
};