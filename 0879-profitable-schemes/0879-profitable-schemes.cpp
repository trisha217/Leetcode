class Solution {
public:
int dp[101][101][101];
    int f(int i,int tpeople,int tprofit,int n,int minProfit,vector<int>&group ,vector<int>&profit){
        
        if(i==group.size()){
           return tprofit>=minProfit;
        }
        if(dp[i][tpeople][tprofit]!=-1){
            return dp[i][tpeople][tprofit];
        }
        int take=0;
        if(tpeople+group[i]<=n){
             take=f(i+1,tpeople+group[i],min(minProfit,tprofit+profit[i]),n,minProfit,group,profit);
        }
        int nontake=f(i+1,tpeople,tprofit,n,minProfit,group,profit);

        int sum=(take+nontake)%1000000007;

       return dp[i][tpeople][tprofit]=sum;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof(dp));
        return f(0,0,0,n,minProfit,group,profit);
    }
};