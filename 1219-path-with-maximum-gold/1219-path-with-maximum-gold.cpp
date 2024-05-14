#define pp pair<int,int>
#define fs first
#define ss second
class Solution {
    vector<int> vi{1,0,-1,0},vj{0,1,0,-1};
public:
    int rec(int i,int j,int &ans,vector<vector<int>>&gold){
        int n=gold.size(),m=gold[0].size(),tmp=0,t=gold[i][j];
        gold[i][j]=0;
        for(int k=0;k<4;k++){
            int p=i+vi[k],q=j+vj[k];
            if(p>=0 && p<n && q>=0 && q<m && gold[p][q]!=0)tmp=max(tmp,rec(p,q,ans,gold));
        }
        gold[i][j]=t;
        ans=max(ans,t+tmp);
        return t+tmp;
    }
    int getMaximumGold(vector<vector<int>>& gold) {
        int n=gold.size(),m=gold[0].size(),ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(gold[i][j]!=0)rec(i,j,ans,gold);
        return ans;
    }
};