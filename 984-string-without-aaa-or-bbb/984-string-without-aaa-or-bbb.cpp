class Solution {
public:
    // Greedy rule:
        // 1. Append the 'a' or 'b' based on which value a and b is greater.
        // 2. Make sure there is not substring 'aaa' or 'bbb' exists. 
    string strWithout3a3b(int a, int b) {
        string res="";
        while(a||b){
            if(a>=b){
                int n=res.size()-1;
                if(res.size() >=2 && res[n]=='a' && res[n-1]=='a'){
                    res.push_back('b');
                    b--;
                }
                else{
                    res.push_back('a');
                    a--;
                }
            }
            else
            {
                int n=res.size()-1;
                if(res.size() >=2 && res[n]=='b' && res[n-1]=='b'){
                    res.push_back('a');
                    a--;
                }
                else{
                    res.push_back('b');
                    b--;
                }
                
            }
        }
        return res;
    }
};