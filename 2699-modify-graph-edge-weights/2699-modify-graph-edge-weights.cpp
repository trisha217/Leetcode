class Solution {
public:
    vector<int> dijks(int source,vector<vector<pair<int,int>>>adj,int n){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n,INT_MAX);
        dist[source] = 0;
        pq.push({0,source});
        while(!pq.empty()){
            auto [wt,idx] = pq.top();
            pq.pop();
            for(auto [it,wei]:adj[idx]){
                if(dist[it] > dist[idx]+wei){
                    dist[it] = dist[idx]+wei;
                    pq.push({dist[it],it});
                }
            }
        }
        return dist;
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<pair<int,int>>>adj(n);//only +ve edges
        for(int i=0;i<edges.size();i++){
            if(edges[i][2]!=-1){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});}
        }

        vector<int>dist = dijks(source,adj,n);

        if(dist[destination] <target){
            return {};
        }
        if(dist[destination] == target){
            for(int i=0;i<edges.size();i++){
                if(edges[i][2] == -1){
                    edges[i][2] = 2*(1e9);
                }
            }
            return edges;
        }
        bool flag  = false;
        for(int i=0;i<edges.size();i++){
            if(edges[i][2]==-1){
                if(flag){
                    edges[i][2] = 2*(1e9);
                }else{
                    edges[i][2] = 1;
                }
                adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
                adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
                if(!flag){
                    dist = dijks(source,adj,n);
                    if(dist[destination] <= target){
                        flag = true;
                        edges[i][2] = target-dist[destination]+1;
                    }
                }
            }
        }
        if(flag){
            return edges;
        }
        return {};
    }
};