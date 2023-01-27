class TrieNode {
public:
    TrieNode* chld[26];
    bool isEnd;
    TrieNode() {
        for(int i = 0; i < 26; i++) {
            chld[i] = NULL;
        }
        isEnd = false;
    }
    void endHere() {
        isEnd = true;
    }
};
class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    TrieNode* getRoot() {
        return root;
    }
    void constructTrie(string word) {
        TrieNode* temp = root;
        int len = word.length();
        for(int i = 0; i < len; i++) {
            if(!temp->chld[word[i] - 'a'])
                temp->chld[word[i] - 'a'] = new TrieNode();
            temp = temp->chld[word[i] - 'a'];
            if(i == len - 1) temp->endHere();
        }
    }
    void trieFromWords(vector<string>& words) {
        for(string &word:words) {
            constructTrie(word);
        }
    }
};
class Solution {
public:
    bool f(string word, int endCnt, TrieNode* root) {
        if(word.empty()) return endCnt > 1;
        TrieNode* temp = root;
        for(int i = 0; i < word.length(); i++) {
            if(temp->chld[word[i] - 'a'])
                temp = temp->chld[word[i] - 'a'];
            else return 0;
            if(temp->isEnd) {
                if(f(word.substr(i + 1), endCnt + 1, root))
                    return 1;
            }
        }
        return 0;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie* trie = new Trie();
        trie->trieFromWords(words);
        vector<string> ans;
        TrieNode* head = trie->getRoot();
        for(string& word:words) {
            if(f(word, 0, head)) ans.push_back(word);
        }
        return ans;
    }
};