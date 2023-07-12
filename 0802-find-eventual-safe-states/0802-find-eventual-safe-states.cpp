class Solution {
public:
    bool dfs(int node,vector<vector<int>> &graph,vector<bool> &vis,vector<bool> &pathVis,vector<bool> &check)
    {
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:graph[node])
        {
            if(!vis[it])
            {
               if(dfs(it,graph,vis,pathVis,check)==1)
                return true;    
            }
            else if(pathVis[it]==1)
                return true;  
        }
        check[node]=1;                                    //marking the node which are not part of cycle
        pathVis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        int n=graph.size();
        vector<bool> vis(n,0),pathVis(n,0),check(n,0);
        for(int i=0;i<n;i++)
            if(!vis[i])
                dfs(i,graph,vis,pathVis,check);
        for(int i=0;i<n;i++)
            if(check[i]==1)
                res.push_back(i);
        return res;
    }
};

