class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // split intervals into groups
        //    each interval is in exactly
        //    none of the intervals in a group overlap
        // return minimum number of groups

        // maybe look at maximum overlap?
        // if there is a point that intersects x intervals
        // then we need at least x groups
        // proof by contra: suppose we had x-1
        // then we can't put the last one in any of those groups because it would overlap point p in those groups
        // so we need x groups

        // can we distribute the rest of the points accordingly? each pattern of +1..-1 +1 ... -1 overlap can be put in the same group
        // a function of that form that has +x as the max can be split into x +1..-1 functions
        // so we can solve the isomorphic problem using x
        // therefore problem reduces to finding max concurrent bookings basically

        // n log(n) sort, or we can use bucket sort instead

        // lets do sort

        vector<pair<int,int>> deltas;
        deltas.reserve(2*intervals.size());
        for (auto const ival : intervals) {
            deltas.emplace_back(ival[0], +1);
            deltas.emplace_back(ival[1]+1, -1);
        }

        sort(deltas.begin(), deltas.end()); // note that the {x,-1} are ordered before {x,+1} which is what we want
        int ans=0, curr=0;
        for (auto const [_, d] : deltas) {
            curr += d;
            ans = max(ans, curr);
        }

        return ans;
    }
};