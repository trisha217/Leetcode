class Solution {
public:
    void dfs(int node,int dest, vector<vector<int>>& graph,vector<int>& d, vector<vector<int>>& path){
        d.push_back(node);
        if(node == dest){
            path.push_back(d);
        }
        else{
           for(auto it: graph[node]){
                dfs(it,dest,graph,d,path);
            } 
        }
        d.pop_back();
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> path;
        vector<int> d;
        dfs(0,graph.size()-1,graph,d,path);
        return path;
    }
};