class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=0; i<n; i++) {
            q.push(i+1);
        }
        int ans = 0;
        while(!q.empty()) {
            ans = q.front();
            for(int i=1; i<k; i++) {
                int front = q.front();
                q.pop();
                q.push(front);
            }
            q.pop();
        }
        return ans;
    }
};