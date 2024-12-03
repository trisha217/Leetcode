#include <sstream>

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int index = 1; // Word index starts from 1

        while (ss >> word) {
            if (word.find(searchWord) == 0) { // Check if searchWord is a prefix
                return index;
            }
            index++;
        }

        return -1;
    }
};