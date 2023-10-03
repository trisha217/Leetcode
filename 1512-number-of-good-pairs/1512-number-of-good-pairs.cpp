class Solution {
public:
    int numIdenticalPairs(vector<int>& vec) {
        int cnt = 0;
        for(int i=0;i<vec.size()-1;i++){
            for(int j =i+1;j<vec.size();j++){
                if(vec[i]==vec[j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};