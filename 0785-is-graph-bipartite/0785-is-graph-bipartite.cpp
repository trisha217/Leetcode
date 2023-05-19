class Solution {
public:
int bfs(int sr,vector<vector<int>>& adj,vector<int> &vis)
{
    vis[sr]=1;
    queue<pair<int,int>> q;
    map<int,int> mp;
    q.push({sr,-1});
    mp[sr]=0;
    while(q.size()>0)
    {
        int a=q.front().first,b=q.front().second;
        q.pop();
        for(int i=0;i<adj[a].size();i++)
        {
            if(vis[adj[a][i]]==0)
            {
                vis[adj[a][i]]=1;
                mp[adj[a][i]]=mp[a]+1;
                q.push({adj[a][i],a});
            }
            else if(adj[a][i]!=b)
            {
                //cout<<adj[a][i]<<sr<<endl;
                if((mp[a]+mp[adj[a][i]])%2==0)
                return 0;
            }
        }
    }
    return 1;
}
	bool isBipartite(vector<vector<int>>& graph){
	    int i,j,p,V=graph.size();
	    vector<int> vis(V,0);
	    for(i=0;i<V;i++)
	    {
	        if(vis[i]==0)
	        p=bfs(i,graph,vis);
	        if(p==0)
	        return false;
	    }
	    return true;
	}
};