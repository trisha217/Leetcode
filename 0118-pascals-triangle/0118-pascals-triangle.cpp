class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> soln;
        if(numRows==1) return {{1}};
        if(numRows==2) return {{1},{1,1}};
        soln.push_back({1});
        soln.push_back({1,1});
        for(int i=2;i<numRows;i++){
            vector<int> v;
            v.push_back(1);
            int j=1;
            while(j!=i){
                v.push_back(soln[i-1][j-1]+soln[i-1][j]);
                if(j+1==i) v.push_back(1);
                j++;
            }
            soln.push_back(v);
            
        }
        return soln;
    }
};