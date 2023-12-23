class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> st;
        int x=0,y=0;
        string position=to_string(x) +"_" + to_string(y);
        st.insert(position);

        for(char &ch : path){
            if(ch == 'E') x++;
            else if(ch == 'W') x--;
            else if(ch == 'N') y++;
            else y--;
            position=to_string(x) + "_" + to_string(y);
            if(st.find(position) != st.end())
            return true;
            st.insert(position);
        }
        return false;
    }
};
