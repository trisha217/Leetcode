class Solution {
public:
    string reverseWords(string s) {
        
        istringstream iss(s); // Used to read the words from string 's'
        string word, result;

        // This loop will run until there are no more words to read
        while (iss >> word) {
            // reversing each word 
            reverse(word.begin(), word.end());
            // Storing the result with reversed words followed by a space
            result += word + " ";
        }

        // This is done to ensure that there is no extra space in the end of the result string
        if (!result.empty()) 
        result.pop_back();
        
        return result;
    }
};