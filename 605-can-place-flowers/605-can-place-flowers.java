class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int prev;
        int total =0;
        int next;
        int size = flowerbed.length;
        if(size == 1 && flowerbed[0]==0 && n==1){
            return true;
        }
        else if(size ==1 && flowerbed[0]==1 && n==1){
            return false;
        }
        else if(size<n){
            return false;
        }
        if(flowerbed[0]==0 && size!=1)
            {
                next = flowerbed[1];
                if(next==0)
                {
                    total++;
                    flowerbed[0]=1;
                }
            }
        if(flowerbed[size-1]==0 && size!=1){
            prev = flowerbed[size-2];
            if(prev==0)
                {
                    total++;
                    flowerbed[size-1]=1;
                }
            
        }
        for(int i=1;i<size-1;i++)
        {
                prev = flowerbed[i-1];
                next = flowerbed[i+1];
                if(prev==0 && next==0 && flowerbed[i]==0)
                {
                    total++;   
                    flowerbed[i]=1;  
                }
        }
        return (n<=total);
    }
}