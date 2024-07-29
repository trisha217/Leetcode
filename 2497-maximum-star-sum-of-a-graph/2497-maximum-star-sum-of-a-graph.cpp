class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        unordered_map<int,priority_queue<int>> mp;
        int n = edges.size();
        int maxsum = *max_element(vals.begin(),vals.end());
        for(int i=0;i<n;i++){
            mp[edges[i][0]].push(vals[edges[i][1]]);
            mp[edges[i][1]].push(vals[edges[i][0]]);
        }
        for(auto it: mp){
            int node = it.first;
            int sum = vals[node];
            int k_ = k;
            while(!it.second.empty() && k_>0){
                int value = it.second.top();
                if(value>0){
                    sum+= value;
                    k_--;
                }
                it.second.pop();
            }
            maxsum = max(sum,maxsum);
        }
        return maxsum;
    }
};