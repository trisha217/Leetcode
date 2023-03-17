typedef struct rec
{
    struct rec* next[26] = {};
    bool leaf = false; 
    rec* insert (char c) {if (!next[c-'a']) next[c-'a'] = new rec(); return next[c-'a'];} 
    rec* search(char c) {return next[c-'a'];} 
} REC;
class Trie {
    REC* trie = new rec();
public:
    Trie() {
        
    }
    
    void insert(string word) {
        REC* next= trie;
        for(auto c: word) next=next->insert(c);
        next->leaf=true;
    }
    
    bool search(string word) {
       REC* next=trie;
       for(auto c: word) {if (!next) break; next=next->search(c);}
       if (next && next->leaf) return true;
       return false;
    }
    
    bool startsWith(string prefix) {
        REC* next=trie;
       for(auto c: prefix) {if (!next) break; next=next->search(c);}
       if (next) return true;
       return false;
    }
};