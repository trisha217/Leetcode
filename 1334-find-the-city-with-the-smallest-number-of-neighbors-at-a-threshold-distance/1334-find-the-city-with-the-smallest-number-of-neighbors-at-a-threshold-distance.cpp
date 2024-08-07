class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int m = edges[0].size();
        vector<vector<int>> dist(n,vector<int> (n,1e9));
        for(auto it: edges){
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        //floyd warshall
        for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (dist[i][k] == 1e9 || dist[k][j] == 1e9)
						continue;
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
        int cntcity = n;
        int cityno = -1;
        for (int city = 0; city < n; city++) {
			int cnt = 0;
			for (int adjCity = 0; adjCity < n; adjCity++) {
				if (dist[city][adjCity] <= distanceThreshold)
					cnt++;
			}
			if (cnt <= cntcity) {
				cntcity = cnt;
				cityno = city;
			}
		}
        return cityno;
    }
};