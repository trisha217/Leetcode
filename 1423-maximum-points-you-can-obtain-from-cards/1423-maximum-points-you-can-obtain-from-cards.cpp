class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int ans = 0;
        int leftSum = 0,rightSum = 0;

         // Calculate the initial sum by taking the first k cards from the left
        for(int i = 0; i < k; i++) leftSum += cardPoints[i];
        
        // Initialize ans with the sum of the first k cards
        ans = max(ans, leftSum + rightSum);
        int lastIndx = n - 1; 

        // Sliding window: Start moving cards from left to right
        for(int i = k - 1; i >= 0; i--) {
            leftSum -= cardPoints[i]; 
            rightSum += cardPoints[lastIndx]; 
            lastIndx -= 1; 
            ans = max(ans, leftSum + rightSum);
        }
        return ans;
    }
};