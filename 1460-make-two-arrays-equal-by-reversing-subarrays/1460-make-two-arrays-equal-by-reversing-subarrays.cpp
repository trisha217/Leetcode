class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int, int> mt;
        map<int, int> mar;
        for(int i=0;i<target.size();i++)
        {
            mt[target[i]]++;
            mar[arr[i]]++;
        }
        if(mt.size()!=mar.size())
        return 0;
        if(mt == mar)
        return 1;
        else return 0;
    }
};