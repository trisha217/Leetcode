class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long> fo(n);
        int n1 = roads.size();
        for(int i=0;i<n1;i++){
            int x1 = roads[i][0];
            int y1 = roads[i][1];
            fo[x1]++;
            fo[y1]++;
        }
        sort(fo.begin(),fo.end());
        long lop=0;
        int w=1;
        for(long gh:fo){
            lop = lop + (gh*w);
            w++;
        }
        return lop;
    }
};