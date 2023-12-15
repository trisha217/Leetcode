class Solution {
public:
    string destCity(vector<vector<string>> &paths) {
        // support variables
        unordered_set<string> from, to;
        // parsing paths
        for (auto &path: paths) {
            auto &currFrom = path[0], &currTo = path[1];
            auto currFromPos = to.find(currFrom);
            // 1st currFrom case: we saw a destination matching currFrom
            if (currFromPos != end(to)) to.erase(currFromPos);
            // 2nd currFrom case: currFrom not matched before
            else from.insert(currFrom);
            auto currToPos = from.find(currTo);
            // 1st currTo case: we saw a starting location matching currTo
            if (currToPos != end(from)) from.erase(currToPos);
            // 2nd currTo case: currTo not matched before
            else to.insert(currTo);
        }
        return *begin(to);
    }
};