class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> ans(n);
        vector<int> q(n);
        iota(std::begin(q), std::end(q), 0);
        sort(deck.begin(),deck.end());
        //2,3,5,7,11,13,17-deck
        //0,1,2,3,4,5,6-q
        for(int i=0;i<n;i++){
            //q -0,1,2,3,4,5,6 for i=0
            //q -2,3,4,5,6,1 for i=1
            //q- 4,5,6,1,3 for i=2
            //q- 6,1,3,5 for i=3
            //q - 3,5,1 for i=4
            //q -1,5 for i=5
            //q - 1 for i=6
            ans[q[0]] = deck[i];
            //ans[0]=2 for i=0
            //ans[2]=3 for i=1
            //ans[4]=5 for i=2
            //ans[6]=7 for i=3
            //ans[3]=11 for i=4
            //ans[1]=13 for i=5
            //ans[1]=17 for i=6
            q.erase(q.begin());
            //q- 1,2,3,4,5,6
            //q- 3,4,5,6,1
            //q - 5,6,1,3
            //q - 1,3,5
            //q- 5,1
            //q -1
            //q - empty
            q.push_back(q[0]);
            //q-1,2,3,4,5,6,1
            //q - 3,4,5,6,1,3
            //q - 5,6,1,3,5
            //q - 1,3,5,1
            //q - 5,1,5
            //q - 1,1
            //q - empty
            q.erase(q.begin());
            //q-2,3,4,5,6,1
            //q - 4,5,6,1,3
            //q - 6,1,3,5
            //q - 3,5,1
            //q - 1,5
            //q -1
            //q - empty
        }
        return ans;
    }
};