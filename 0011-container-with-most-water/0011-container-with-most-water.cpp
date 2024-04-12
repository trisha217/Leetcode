class Solution {
public:
    int maxArea(vector<int>& height) {
       int n=height.size();
        int l=0;
        int r= n-1;
        int ans;
        int maxi = INT_MIN;
        while(l<=r){
            ans = (r-l) * min(height[l],height[r]);
            maxi = max(ans,maxi);
            if(height[l]<=height[r]){
                l++;
            }
            else{    
                r--;
            }
        }
        return maxi; 
    }
};
