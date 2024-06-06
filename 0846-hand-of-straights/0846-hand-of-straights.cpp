class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
       map<int,int>m; for(auto K:hand)m[K]++;

       for(auto K:m){ // iterating in the map ---(1)
        int x=K.first; 
        if(K.second==0)continue;

            for(int i=x; i<x+groupSize; i++){ // ---(2)
                m[i]=m[i]-K.second;
                if(m[i]<0)return false;
            }

       }
       return true;
    }

    // (1) & (2) together constitute a loop of O(N) since we are eliminating elements

    // solution is O(N * log(n))
};