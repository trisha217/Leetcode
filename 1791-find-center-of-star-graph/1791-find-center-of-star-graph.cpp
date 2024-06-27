class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> freqMp;
        for(auto & ed : edges){
            freqMp[ed[0]]++;
            freqMp[ed[1]]++;
        } 
        int maxFreq = 0, maxFreqVert = 0;
        for(auto & pr : freqMp){
           int vertFreq = pr.second, vertValue = pr.first; 
           if(maxFreq < vertFreq){
              maxFreqVert = vertValue;
              maxFreq = vertFreq;
           }
        }
        return maxFreqVert; 
    }
};