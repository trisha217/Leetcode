//class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int l=0,r=0,maxlen=0;
//         map<char,int> mpp;
//         while(r < s.size()){
//             mpp[s[r]]++;
//             if(mpp.size() > k){
//                 mpp[s[l]]--;
//                 if(mpp[s[l]] == 0){
//                     mpp.erase(s[l]);
//                 }
//                 l++;
//             }
//             if(mpp.size() <= k){
//                 maxlen = max(maxlen,r - l + 1);
//             }
//             r++;
//         }
//         return maxlen;
//     }
// };
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxf = 0;
        int len = s.size();
        int maxlen = 0;
        for(int i=0;i<len;i++){
            vector<int> hash(26,0);
            for(int j=i;j<len;j++){
                hash[s[j]-'A']++;
                maxf = max(maxf,hash[s[j]-'A']);
                int changes = (j-i+1) - maxf;
                if(changes <= k){
                    maxlen = max(maxlen, j - i + 1);
                }
                else{
                    break;
                }
            }
        }
        return maxlen;
    }
};