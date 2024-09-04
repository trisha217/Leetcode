class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> obstacleSet;
        for (const auto& obs : obstacles) {
            obstacleSet.insert({obs[0], obs[1]});
        }

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int direction = 0;

        int x = 0, y = 0;
        int maxDistanceSquared = 0;

        for (int command : commands) {
            if (command == -2) {
                direction = (direction + 3) % 4;
            } else if (command == -1) {
                direction = (direction + 1) % 4;
            } else {
                int dx = directions[direction].first;
                int dy = directions[direction].second;
                for (int step = 0; step < command; ++step) {
                    int nextX = x + dx;
                    int nextY = y + dy;
                    if (obstacleSet.count({nextX, nextY}) > 0) {
                        break;
                    }
                    x = nextX;
                    y = nextY;
                    maxDistanceSquared = max(maxDistanceSquared, x * x + y * y);
                }
            }
        }

        return maxDistanceSquared;
    }
};