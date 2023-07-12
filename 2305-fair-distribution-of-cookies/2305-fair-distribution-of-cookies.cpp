class Solution {
public:
    int ans = INT_MAX ;
    void fun(vector<int>&v , int in , vector<int>&c){
        if(in == v.size()){
            int y = 0;
            for(auto x : c){
                y = max(y , x);
            }
            ans = min(ans , y);
            return ;
        }

        for(int i=0 ; i<c.size() ; i++){
            c[i] += v[in];
            fun(v , in+1 , c);
            c[i] -= v[in];
        }

        return ;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>c(k , 0);
        fun(cookies , 0 , c);
        return ans ;
    }
};