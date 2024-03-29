class Solution {
    UglyNumber ugly=new UglyNumber();
    
    public int nthUglyNumber(int n) {
        
        return ugly.result[n-1];
    }
}

class UglyNumber{
    int[] result;
    
    public UglyNumber(){
        result=new int[1690];
        result[0]=1;
        
        int v2=0,v3=0,v5=0;
        
        for(int i=1;i<1690;i++){
            
            result[i]=Math.min(result[v2]*2,Math.min(result[v3]*3,result[v5]*5));

            if(result[i]==result[v2]*2){
                v2++;
            }
            if(result[i]==result[v3]*3){
                v3++;
            }
            if(result[i]==result[v5]*5){
                v5++;
            }
            
        }
    }
}