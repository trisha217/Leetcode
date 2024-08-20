class Solution {
public:
    int t=0;
    int dp[501][501][2];
    bool solve(vector<int>&v , int beg , int end , int alice , int win){
        //base case
        if(beg > end){
            if(win > t/2){
                return true ;
            }
            return false ;
        }
        if(dp[beg][end][alice] != -1){
            return dp[beg][end][alice] ;
        }
        bool ans = false ;
        if(alice == 1){
            ans = solve(v,beg+1,end,0,win+v[beg]) || solve(v,beg,end-1,0,win+v[end]);
        }
        else{
            ans = solve(v,beg+1,end,1,win) || solve(v,beg,end-1,1,win);
        }

        return dp[beg][end][alice] = ans ;
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp , -1 , sizeof(dp));
        for(auto x : piles){
            t += x ;
        }
        return solve(piles ,0,piles.size()-1,1,0) ;
    }
};