class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1==sentence2) return true;

        vector<string> s1,s2;
        stringstream ss1(sentence1),ss2(sentence2);
        string word;

        while(ss1>>word) s1.push_back(word);
        while(ss2>>word) s2.push_back(word);

        int s1s=0; int s1e=s1.size()-1;
        int s2s=0; int s2e=s2.size()-1;

        while(s1s<=s1e && s2s<=s2e && s1[s1s]==s2[s2s]){
            s1s++;
            s2s++;
        }

        while(s1e>=s1s && s2e>=s2s && s1[s1e]==s2[s2e]){
            s1e--;
            s2e--;
        }

        return s1e<s1s || s2e<s2s;
    }
};