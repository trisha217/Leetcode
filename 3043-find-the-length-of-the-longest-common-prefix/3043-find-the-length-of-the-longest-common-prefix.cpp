class Solution {
public:

    class trie {
    public:
        vector<trie*> children;
        bool is_leaf = false;

        trie(bool leaf) : is_leaf(leaf) { children = vector<trie*>(10, nullptr); }
    };

    void add_trie(trie *t, int num, int ind, int size) {
        if (t->children[get_ith(num, ind, size)] == nullptr) {
            t->children[get_ith(num, ind, size)] = new trie(false);
        }

        if (ind == size - 1) {
            t->children[get_ith(num, ind, size)]->is_leaf = true;
        } else {
            add_trie(t->children[get_ith(num, ind, size)], num, ind + 1, size);
        }

    }

    int find_trie(trie *t, int num, int ind, int size) {
        if (ind == size - 1) {
            if (t->children[get_ith(num, ind, size)] != nullptr) {
                return ind + 1;
            }
            return ind;
        }
        return t->children[get_ith(num, ind, size)] == nullptr ? ind : find_trie(t->children[get_ith(num, ind, size)], num, ind + 1, size);
    }

    int get_ith(int num, int i, int size) {
        if (size - i - 1 == 0) return num % 10;
        return int(num / pow(10, size - i - 1)) % 10;
    }

    int count_digs(int num) {
        int digs = 0;
        while (num > 0) {
            digs++;
            num = num / 10;
        }
        return digs;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        trie* t = new trie(false);
        for (int num : arr1) {
            add_trie(t, num, 0, count_digs(num));
        }
        int res = 0;
        for (int num : arr2) {
            int len =  find_trie(t, num, 0, count_digs(num));
            res = max(res, len);
        }
        return res;
    }
};