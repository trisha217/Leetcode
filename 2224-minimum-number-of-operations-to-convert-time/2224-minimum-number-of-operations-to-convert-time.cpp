class Solution {
public:
    int getTimeInMinutes(string &s){
        return stoi(s.substr(0,2))*60 + stoi(s.substr(3));
    }
    int convertTime(string current, string correct) {
        int currentTime = getTimeInMinutes(current);
        int correctTime = getTimeInMinutes(correct);
        int diff = correctTime-currentTime;
        int ops[4]= {60,15,5,1};
        int ans =0;
        for(int i=0;i<4;i++){
            ans = ans + (diff/ops[i]);
            diff = diff % ops[i];
        }
        return ans;
    }
};