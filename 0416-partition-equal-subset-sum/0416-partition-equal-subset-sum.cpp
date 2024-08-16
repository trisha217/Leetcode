class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            sum = sum + arr[i];
        }
        if(sum%2==1){
            return false;
        }
        sum = sum/2;
        vector<bool> prev(sum + 1, false);
        vector<bool> cur(sum + 1, false);
        prev[0]= cur[0] = true;
        if(arr[0] <= sum)
            prev[arr[0]] = true;
        for(int ind=1;ind<n;ind++)
        {
            for(int target=1;target<=sum;target++)
            {
                bool pick = false, notpick;
                if(arr[ind] <= target)
                    pick = prev[target-arr[ind]];
                notpick = prev[target];
                cur[target] = notpick || pick;
            }
            prev = cur;
        }
        return prev[sum];
    }
};