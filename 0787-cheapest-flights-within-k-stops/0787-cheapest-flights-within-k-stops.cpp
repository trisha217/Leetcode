#define pipii pair<int,pair<int,int>>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adjList[n];
        // Create an adjacency list
        for(auto i:flights){
            adjList[i[0]].push_back({i[1],i[2]});
        }
        // Dist matrix for each stops 0 to k values
        vector<vector<int>>dist(n,vector<int>(k+1,1e9));
        
        // minHeap for cost
        // {Cost,{count,city}}
        priority_queue<pipii,vector<pipii>,greater<pipii>>pq;

        // Add intital distance with src to 0
        dist[src][0]=0;
        // Push {cost=0,{count=0,city=src}} to min Heap
        pq.push({0,{0,src}});

        // BFS Traverse
        while(!pq.empty()){
            auto topVal=pq.top();
            pq.pop();
            // Get the top values.
            int currDist=topVal.first;
            int cnt=topVal.second.first;
            int node=topVal.second.second;

            // If count exceeds k then skip the next steps.
            if(cnt>k)continue;

            // Iterate all the children of node
            for(auto i:adjList[node]){
                int d=i.second;
                int nxtNode=i.first;
                // Get the new distance 
                int newDist=currDist+d;
                // If that dist is less than current distance
                if(dist[nxtNode][cnt]>newDist){
                    dist[nxtNode][cnt]=newDist;
                    // Push to the minHeap
                    pq.push({dist[nxtNode][cnt],{cnt+1,nxtNode}});
                }
            }
        }
        int ans=1e9;
        // Now get the minimum value of each distance with values 0 to k
        for(int i=0;i<=k;i++){
            ans=min(ans,dist[dst][i]);
        }
        // Return ans
        return ans==1e9?-1:ans;
    }
};