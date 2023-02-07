class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        queue<pair<int,int>>qm;
        int t1=-2,t2=-2;
        int mx=-1;
        int cnt=0;
        for(int i=0;i<fruits.size();i++){
            if(qm.size()<2){
                if(qm.size()==1 && qm.front().first==fruits[i] ){
                    qm.front().second+=1;
                    cnt++;
                }
                else{
                    qm.push(make_pair(fruits[i],1));
                    cnt++;
                }
            }
            else if(fruits[i]==qm.front().first  || fruits[i]==qm.back().first ){
                cnt++;
                if(fruits[i]==qm.front().first){
                    if(fruits[i]==fruits[i-1]){
                         qm.front().second+=1;
                    }
                    else{
                         qm.front().second=1;
                    }
                }
                else if(fruits[i]==qm.back().first){
                    if(fruits[i]==fruits[i-1]){
                         qm.back().second+=1;
                    }
                    else{
                         qm.back().second=1;
                    }
                }  
            }
            else if(fruits[i]!=qm.front().first   && fruits[i]!=qm.back().first){
                if(fruits[i-1]==qm.front().first){
                    //remove back of qm
                    cnt=1;
                    cnt=cnt+qm.front().second;
                    auto frnt=qm.front();
                    qm.pop();
                    qm.pop();
                    qm.push(frnt);
                }
                else if(fruits[i-1]==qm.back().first) {
                    //remove front of qm
                    cnt=1;
                    cnt=cnt+qm.back().second;
                    qm.pop();
                }
                else{
                    cnt=1;
                }
                qm.push(make_pair(fruits[i],1));
                               
            }
            // cout<<cnt<<endl;
            if(cnt>mx){
                mx=cnt;
            }
        }
        return mx;
    }
};