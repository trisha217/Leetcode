class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> s;
        int i=0, count=1;
        while(count<=n && i<target.size()){
            s.push_back("Push");
            if(count == target[i]){
                i++, count++;
            }else{
                s.push_back("Pop");
                count++;
            }
        }
        return s;
    }
};