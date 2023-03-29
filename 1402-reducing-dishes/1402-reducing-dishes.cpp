class Solution {
public:
    int pep(vector<int>& s, int p){
        int a = 0;
        int t = 1;
        for(int i=p;i<s.size();i++){
            a += (t) * s[i];
            t++;
        }
        return a;
    }
    
    int maxSatisfaction(vector<int>& s) {
        int maxi = 0;
        sort(s.begin(), s.end());
        for(int i=0;i<s.size();i++){
            int m = pep(s, i);
            if(m > maxi){
                maxi = m;
            }
        }
        return maxi;
    }
};