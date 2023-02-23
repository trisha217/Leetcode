class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
        priority_queue<int>pq;
        vector<pair<int,int>>arr;

        int n=profits.size();

        for(int i=0;i<n;i++)
        {
            arr.push_back({capital[i],profits[i]});
        }
        sort(arr.begin(),arr.end());

        int ind=0;
        for(int i=0;i<k;i++)
        {
            while(ind<n && arr[ind].first<=w)
            {
                pq.push(arr[ind].second);
                ind++;
            }
            if(pq.empty())
            {
                return w;
            }
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};