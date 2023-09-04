class Solution {
public:
    int bfs(int n,vector<vector<int>> &adj){
        vector<int> dist(n+1,1e9);
        queue<pair<int,int>> q;
        q.push({0,0});
        dist[0]=0;
        while(!q.empty()){
            int curr = (q.front()).first;
            int dis = (q.front()).second;
            q.pop();
            for(auto neg : adj[curr]){
                if(dist[neg]<=dis+1) continue;
                dist[neg] = dis+1;
                q.push({neg,dist[neg]});   
            }
        }

        return dist[n]==1e9 ? -1 : dist[n];
    }
    int minTaps(int n, vector<int>& range) {
        vector<pair<int,int>> jump;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<=n;i++){
                int lef = max(0,i-range[i]);
                int rig =min(i+range[i],n);
                jump.push_back({lef,rig});
        }
        
        for(int t=0;t<=n;t++){
              int start = jump[t].first;
              int end = jump[t].second;

              for(int k=start+1;k<=end;k++){
                  adj[start].push_back(k);
              }
        }

        return bfs(n,adj);
    }
};