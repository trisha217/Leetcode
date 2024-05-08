class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int,int> mp;
        int size=score.size();
        vector<string> ans(size);
        for(int i=0;i<score.size();i++){
            mp[score[i]]=i;
        }
        int n =size;
        for(auto x : mp){
            int pos = x.second;
            if(n==1) ans[pos]="Gold Medal";
            else if(n==2) ans[pos]="Silver Medal";
            else if(n==3) ans[pos]="Bronze Medal";
            else ans[pos]=to_string(n);
            n--;
        }
        return ans;
    }
};