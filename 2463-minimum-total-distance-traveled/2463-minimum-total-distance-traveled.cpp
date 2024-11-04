class Solution {
    long long solve(int i, int j, vector<int>& r, vector<long long>& f , vector<vector<long long>>&dp){
        if(i>=r.size() ){
            return 0;
        }
        if(j>=f.size()){
            return 1e12;
        }
       if(dp[i][j]!=-1){
        return dp[i][j];
       }

        long long take=LLONG_MAX;

    
        take=abs(r[i]-f[j])+solve(i+1, j+1, r, f, dp);
          
           
        
       
         return dp[i][j]= min(take, solve(i, j+1, r, f, dp));
        
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        long long distance=0;
        int n=robot.size();
        int m=factory.size();

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<long long> pos;

        for(int i=0; i<m; i++){
            int limit=factory[i][1];
            int poss=factory[i][0];

            for(int j=0; j<limit; j++){
                pos.push_back(poss);
            }
        }
        vector<vector<long long>> dp(n, vector<long long>(pos.size(), -1));

       
        return solve(0, 0, robot, pos, dp);
    }
};