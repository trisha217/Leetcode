class Solution {
public:
    bool static mycmp(pair<double,double> a, pair<double,double> b){
        return (a.first/ a.second ) < (b.first/b.second);
    }
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int k) {
        int n = q.size();
        double ans = 0;
        vector<pair<double,double>> v;
        for(int i = 0 ;i <n ;i++) v.push_back({w[i] , q[i]});
        
        sort(v.begin() , v.end() , mycmp);
        priority_queue<double> pq;
        double quality  = 0;
        double ratio = 0 ;

        for(int i=0;i<k ;i++){
            quality+= v[i].second;
            pq.push(v[i].second);
            ratio  = v[i].first/v[i].second; 
        }
        ans = ratio *  quality;

        for(int  i = k ; i < n ;i++){
            quality-=(pq.top());
            quality+=v[i].second;
            pq.pop();
            pq.push(v[i].second);
            ratio  = v[i].first/v[i].second; 
            ans =  min(ans, ratio *  quality);
        }
        return ans;
    }
};