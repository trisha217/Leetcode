class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adjRev[V];
        vector<int> indegree(V,0);
		for (int i = 0; i < V; ++i) {
            // i -> it
			// it -> i
			for (auto it : graph[i]) {
				adjRev[it].push_back(i);
				indegree[i]++;
			}
        }
        queue<int> q;
	    vector<int> ans;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto it: adjRev[node]){
	            indegree[it]--;
	            if(indegree[it]==0){
	                q.push(it);
	            }
	        }
	    }
        sort(ans.begin(),ans.end());
	    return ans;
    }
};