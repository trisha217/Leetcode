class Solution {
public:
    
    int findDisStr(vector<string>& arr, int N)
{

    unordered_set<string> DistString;
 
    // Traverse the array
    for (int i = 0; i < N; i++) {
 
        if (!DistString.count(arr[i])) {
            DistString.insert(arr[i]);
        }
    }
        int count=0;
 
    // Traverse the set DistString
    for (auto String : DistString) {
 
        // Print distinct string
        count++;
    }
        return count;
}
    
    
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> res;
        string arr[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(int i=0;i<words.size();i++){
            string w="";
            for(int j=0;j<words[i].size();j++){
                char c= words[i][j];
                int num = (int)c -97;;
                w+=arr[num];
            }
            res.push_back(w);
            
            
        }
        int ans = findDisStr(res,res.size());
            return ans;
    }
};