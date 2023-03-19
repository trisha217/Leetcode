class WordDictionary {
public:
    vector<string> v;
    WordDictionary() {}
    
    void addWord(string word) 
    {
        v.push_back(word);
    }
    
    bool search(string word) 
    {
        int cnt = 0;
        int n = word.size();
        for(int i = 0; i < v.size(); i++){
            //proceed for checking only if sizes match
            if(n == v[i].size())
            {
                for(int j = 0; j < n; j++)
                {
                    if(v[i][j] == word[j] || word[j] == '.')
                        cnt++;
                    
                    else{
                        //not a match, make default settings and run the process again
                        cnt = 0;
                        break;
                    }
                }
                
                if(cnt == n) 
                    return true;
            }
        }


        //all matching done but found nothing
        return false;
    }
};