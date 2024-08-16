class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
       vector<int> v_max;
       vector<int> v_min;
vector<vector<int>> v0=arrays;
       for(int i=0;i<v0.size();i++)
       {
          int t1=v0[i][0];
          int t2=v0[i][0];
          for(int j=0;j<v0[i].size();j++)
          {
             t1=max(t1,v0[i][j]);
             t2=min(t2,v0[i][j]);
          }
          v_max.push_back(t1);
          v_min.push_back(t2);
       }


       int m=-1;
      
      vector<int> v_maxs=v_max;
      sort(v_maxs.begin(),v_maxs.end());
int k=v_maxs[v_maxs.size()-1],l=v_maxs[v_maxs.size()-2];
      for(int i=0;i<v_min.size();i++)
      {
         if(k!=v_max[i])
         {
            m=max(m,abs(k-v_min[i]));
         }
         else
         {
             m=max(m,abs(l-v_min[i]));
         }
      }



       return m;

    }
};