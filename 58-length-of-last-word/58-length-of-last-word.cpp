class Solution {
public:
    
    string& leftTrim(string& str, string& chars)
    {
        str.erase(0, str.find_first_not_of(chars));
        return str;
    }
    
    string& rightTrim(string& str, string& chars)
    {
        str.erase(str.find_last_not_of(chars) + 1);
        return str;
    }

    string& trimString(string& str, string& chars)
    {
        return leftTrim(rightTrim(str, chars), chars);
    }
    
    int lengthOfLastWord(string s) {
        string t =" "; 
        int cnt =0;
        string f = trimString(s, t);
        for(int i=f.size()-1;i>=0;i--){
            if(f[i]!=' '){
                cnt++;
            }
            else
            {
                break;
            }
        }
        return cnt;
    }
};