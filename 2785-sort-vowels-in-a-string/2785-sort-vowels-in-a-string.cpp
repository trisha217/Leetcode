class Solution {
     static bool compare(char a, char b) {
        // Calculate the number of set bits (1s) in the binary representation of a and b
       return (int)a>(int)b;
    }
public:
    string sortVowels(string s) {
      vector<char>vowels={'A','E','I','O','U','a','e','i','o','u'};

      vector<char>take;
      for(int i=0;i<s.size();i++){
          if(binary_search(vowels.begin(),vowels.end(),s[i])){
              take.push_back(s[i]);
          }
      }
 //sort them in reverse order so that we ca place according to ascii
      sort(take.begin(),take.end(),compare);
     
      for(int i=0;i<s.size();i++){
           if(binary_search(vowels.begin(),vowels.end(),s[i])){
             s[i]=take.back();
             take.pop_back();
          }
      }

      return s;

        
    }
};