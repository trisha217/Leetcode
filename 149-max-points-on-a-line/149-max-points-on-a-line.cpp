class Solution {
    double getSlope(double x1, double y1, double x2,double  y2)
    {
        return (y2-y1)/(x2-x1);
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = 0;
        for(int i=0; i<n; i++)
        {
            unordered_map<double, int> mp;
            int x1 = points[i][0], y1 = points[i][1];
            int same = 0;
            for(int j =i+1; j<n; j++)
            {
                int x2 = points[j][0], y2 = points[j][1];
                if(x1 == x2 )
                {
                    same++;
                    continue;
                }
                double slope = getSlope(x1, y1, x2, y2);
                mp[slope]++;
                m = max(m, mp[slope]);
            }
            m = max(m, same);
        }
        return m+1;
    }
};