class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n,1e9);
        dist[src]=0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it = q.front();
            int stops = it.first;
            int node = it.second.first;
            int dis = it.second.second;
            q.pop();
            if(stops > k){
                continue;
            }
            for(auto neighbour: adj[node]){
                int v = neighbour.first;
                int wt = neighbour.second;
                if(wt + dis < dist[v] && stops<=k){
                    dist[v] = wt + dis;
                    q.push({stops+1,{v,dist[v]}});
                }
            }  
        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
    }
};