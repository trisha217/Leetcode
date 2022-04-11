class Solution {
public:
    vector<int> searchRange(vector<int>& v, int key) {
        int n = v.size();
        int start = 0;
        int end = n - 1;
        int fres = -1;
        int lres = -1;

  while (start <= end) 
  {
    int mid = start + (end - start) / 2;
    if (v[mid] == key) {
      fres = mid;
      end = mid - 1;

    } else if (key < v[mid]) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
         start = 0;
        end = n - 1;
        while (start <= end) 
  {
    int mid = start + (end - start) / 2;
    if (v[mid] == key) {
      lres = mid;
        start = mid + 1;
      

    } else if (key < v[mid]) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
        vector<int> ans;
        ans.push_back(fres);
        ans.push_back(lres);
     return ans;   
    }
};