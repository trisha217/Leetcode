class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        int n = rating.size();
        for(int i=0;i<n;i++){
            int lessleft =0, lessright=0, greatleft=0, greatright=0;
            for(int j=0;j<i;j++){
                if(rating[j]<rating[i]){
                    lessleft++;
                }
                else if(rating[j]>rating[i]){
                    greatleft++;
                }
            }
            for(int j=i+1;j<n;j++){
                if(rating[j]<rating[i]){
                    lessright++;
                }
                else if(rating[j]>rating[i]){
                    greatright++;
                }
            }
            ans+=lessleft * greatright;
            ans+=lessright * greatleft;
        }
        return ans;
    }
};