class Solution {
public:
    int countConsistentStrings(string a, vector<string>& w) {
        int count = 0;
        for(int i = 0;i<w.size();i++){
            int c = 0;
            for(int j = 0;j<w[i].size();j++){
                for(int k = 0;k<a.size();k++){
                    if(w[i][j] == a[k]){
                        c++;
                        break;
                    }
                }
            }
                if(c==w[i].size()){
                    count++;
            }
        }
        return count;
    }
};