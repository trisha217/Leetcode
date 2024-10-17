class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        priority_queue<int>pq;
        while(num>0){
            pq.push(num%10);
            num/=10;
        }
        int i=0;
        while(!pq.empty()){
            auto tp= pq.top(); pq.pop();
            if(tp==str[i]-'0') i++;
            else{
                int k=i;
                for(int j=i; j<(int)str.size(); j++){
                    if(str[j]-'0'==tp){
                        k=j;
                    }
                }
                swap(str[i], str[k]);
                return stoi(str);
            }
        }
        return stoi(str);
    }
};