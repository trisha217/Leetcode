class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<unordered_map<int,unordered_map<int,bool>>>adjList(n);
        
        for(auto i:redEdges){
            adjList[i[0]][i[1]][true]=true;
        }
        for(auto i:blueEdges){
            adjList[i[0]][i[1]][false]=true;
        }

        vector<vector<int>>dp(n,vector<int>(2,1e9));
        dp[0][0]=0;
        dp[0][1]=0;

        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,-1}});

        while(!q.empty()){
            auto topVal=q.front();
            q.pop();

            int dist=topVal.first;
            int node=topVal.second.first;
            int parent=topVal.second.second;

            for(auto edge:adjList[node]){
                int newDist=dist+1;

                if(parent==-1){
                    if(edge.second[0]){
                        dp[edge.first][0]=newDist;
                        q.push({newDist,{edge.first,0}});
                    }
                    if(edge.second[1]){
                        dp[edge.first][1]=newDist;
                        q.push({newDist,{edge.first,1}});
                    }
                }
                else if(edge.second[!parent] and dp[edge.first][!parent]>newDist){
                    dp[edge.first][!parent]=newDist;
                    q.push({newDist,{edge.first,!parent}});
                }
            }
        }
        vector<int>ans;
        for(auto i:dp){
            int val=min(i[0],i[1]);
            if(val==1e9){
                ans.push_back(-1);
            }
            else{
                ans.push_back(val);
            }
        }
        ans[0]=0;
        return ans;
    }
};