class Solution {
    public int countOdds(int low, int high) {
        int diff = (high-low);
        int ans;
        if(low%2 ==0 && high%2==0)
        {
            ans = diff/2;
        }
        else if(low%2 !=0 && high%2!=0){
            ans = diff/2 + 1;
        }
        else{
            ans = diff/2 + 1;
        }
        return ans;
    }
}