class Solution {
public:
vector<vector<int>> graph ;
vector<int> temp ;
void fun(int i , int x){
    temp[i]=x ;
    for(auto d:graph[i]){
        if(temp[d]==-1) fun(d,x) ;
    }
}
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        graph=vector<vector<int>>(26) ;
        temp=vector<int>(26,-1) ;
        for(int i=0 ; i<s1.length() ; i++){
            int x=s1[i]-'a' , y=s2[i]-'a';
            graph[y].push_back(x) ;
            graph[x].push_back(y) ;
        }
        for(int i=0 ; i<26 ; i++){
            if(temp[i]==-1) fun(i,i) ;
        }
        for(int i=0 ; i<baseStr.length() ; i++){
            int x=baseStr[i]-'a' ;
            if(temp[x]!=-1)baseStr[i]=temp[x]+'a' ; 
            else baseStr[i]=x+'a' ;
        }
        return baseStr ;
    }
};