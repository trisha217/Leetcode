class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                factors.push_back(i);
            }
        }
        for(int i=0;i<factors.size();i++){
            cout<<i<<factors[i]<<endl;
        }
        //cout<<endl;
        int len = factors.size();
        //cout<<factors[k-1];
        if(len<k){
            return -1;
        }
        else
        {
            return factors[k-1];
        }
    }
};