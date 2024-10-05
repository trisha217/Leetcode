class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s2.size()<s1.size()) return false;
        vector<int> alphabet(26,0);
        int characters=0;
        for(char c:s1){
            if(alphabet[c-'a']==0){
                characters++;
            }
            alphabet[c-'a']++;
        }
        //cout<<characters<<endl;
        int n=s1.size();
        int start=0, end=0;
        while(end<n){
            if(alphabet[s2[end]-'a']==0){
                characters++;
            }
            alphabet[s2[end]-'a']--;
            if(alphabet[s2[end]-'a']==0){
                characters--;
            }
            end++;
        }
        if(characters==0) return true;
        end--;
        while(end<s2.size()-1){
            if(alphabet[s2[start]-'a']==0){
                characters++;
            }
            alphabet[s2[start]-'a']++;
            if(alphabet[s2[start]-'a']==0){
                characters--;
            }
            //cout<<"start: "<<characters<<endl;
            start++;
            end++;
            if(alphabet[s2[end]-'a']==0){
                characters++;
            }
            alphabet[s2[end]-'a']--;
            if(alphabet[s2[end]-'a']==0){
                characters--;
            }
            //cout<<"end: "<<end<<" "<<characters<<endl;
            if(characters==0) return true;
        }
        return false;
    }
};