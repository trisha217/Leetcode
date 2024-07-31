class Solution {
public:

    int solve(vector<vector<int>>& books, int shelfwidth, int i, vector <int> &dp) {

        if(i == books.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int pick = INT_MAX, mini = INT_MAX, maxi = INT_MIN, thick = 0;

        for(int j = i; j < books.size(); j++) {

            maxi = max(maxi, books[j][1]);

            thick += books[j][0];

            if(thick <= shelfwidth)

            pick = maxi + solve(books, shelfwidth, j+1, dp);

            else break;

            mini = min(mini, pick);
        }

        return dp[i] = mini;
    }


    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {

        vector <int> dp(books.size(),-1);

        return solve(books, shelfWidth, 0, dp);
        
    }
};