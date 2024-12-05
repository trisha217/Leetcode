class Solution {
public:
    bool canChange(string s, string t) {
        int cur=0, n = s.size();
        vector<int> prel(n+1,0),prer(n+1,0);
        vector<int> Ls,Lt,Rs,Rt;
        string ss,tt; // without '_'
        for(int i=0; i<n; i++){
            if(s[i]=='L'){
                cur++;
                Ls.push_back(i);
            }
            if(t[i]=='L') Lt.push_back(i);
            prel[i+1] = cur;
            if(s[i]!='_') ss.push_back(s[i]);
            if(t[i]!='_') tt.push_back(t[i]);
        }
        if(ss!=tt) return false; // relative order;
        cur = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='R'){
                cur++;
                Rs.push_back(i);
            }
            if(t[i]=='R') Rt.push_back(i);
            prer[i+1] = cur;
        }
        if(Ls.size()!=Lt.size() || Rs.size()!=Rt.size()) return false;

        for(int i=0; i<Ls.size(); i++){
            auto a = Ls[i]+1, b = Lt[i]+1;
            if(a<b) return false;
            if(prer[a] - prer[b-1] != 0) return false;
        }
        for(int i=0; i<Rs.size(); i++){
            auto a = Rs[i]+1, b = Rt[i]+1;
            if(a>b) return false;
            if(prel[a] - prel[b-1] != 0) return false;
        }
        return true;
    }

};