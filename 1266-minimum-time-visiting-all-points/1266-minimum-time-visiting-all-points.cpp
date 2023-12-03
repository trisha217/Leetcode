class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int a=0,ans=0,max=-1;
        for(int i=0; i<points.size()-1; i++){
            for(int j=0; j<2; j++){
                if(points[i][j]<=points[i+1][j])
                a=points[i+1][j]-points[i][j];
                if(points[i][j]>=points[i+1][j])
                a=points[i][j]-points[i+1][j];
                if(max<a){
                max=a;  
                }
            }
            ans=ans+max;
            max=-1;
        }
        return ans;
    }
};