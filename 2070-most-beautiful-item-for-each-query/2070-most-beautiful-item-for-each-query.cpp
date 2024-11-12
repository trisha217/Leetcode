class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = queries.size();

        sort(items.begin(),items.end());

        //store the prefix maximum Beauty
        vector<int> prefixmaxBeauty(items.size() , 0);
        prefixmaxBeauty[0] = items[0][1];

        for(int i = 1 ; i < items.size() ;i++){
            prefixmaxBeauty[i] = max(items[i][1] , prefixmaxBeauty[i - 1]);
        }

        vector<int> maxBeauty(n , 0);

        for(int i = 0 ; i < n ;i++){
            int s = 0  , e = items.size() - 1;
            int index = -1;
            while(s <= e){
                int mid = s + ((e - s) / 2);

                if(items[mid][0] <= queries[i]){
                    index = mid;
                    s = mid + 1;
                }
                else{
                    e = mid - 1;
                }
            }

            if(index != -1)         maxBeauty[i] = prefixmaxBeauty[index];
        }

        return maxBeauty;
    }
};