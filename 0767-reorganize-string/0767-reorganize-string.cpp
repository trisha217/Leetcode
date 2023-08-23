class Solution {
public:
    void gen(pair<int,char> v[],int s,string &ans,int n) {
        for(int i = 0; i < 26; i++) {
            while(s < n && v[i].first) {
                v[i].first--;
                ans[s] = v[i].second;
                s += 2;
            }
        }
    }
    string reorganizeString(string s) {
        pair<int,char> v[26];
        for(auto &i : s) {
            v[i-'a'].first++;
            v[i-'a'].second = i;
        }
        sort(v,v+26,[&](pair<int,char> &a,pair<int,char> &b) {
            return a.first > b.first;
        });
        int n = s.size();
        if(v[0].first > (n+1)/2) return "";
        string ans(n,' ');
        gen(v,0,ans,n);
        gen(v,1,ans,n);
        return ans;
    }
};