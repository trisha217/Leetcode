class Solution {
public:
    int majorityElement(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size();
        if(n==1){
            return v[0];
        }
        int t =(n/2)+1;
        int count=1;
        for(int i=0;i<n-1;i++){
            if(v[i]==v[i+1]){
                count++;
                if(count>=t)
                {
                    return v[i];
                }
            }
            else{
                count=1;
            }
        }
        return 0;
    }
};