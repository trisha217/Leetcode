class Solution {
public:
    string addSpaces(string s, vector<int>& arr) {
        string ans="";
        for(int i=0;i<arr.size();++i){
            if(i==0){
                // if index is zero then number of character's in word should be equal to arr[0] 
                // starting from index zero of string
                ans+=s.substr(0,arr[i]);
            }
            else{
                // if index is not zero then number of character's in word should be equal to (arr[current]-arr[previous]) 
                // index of string
                ans+=" "+s.substr(arr[i-1],arr[i]-arr[i-1]);
            }
        }
        // edge case for adding the last word of string.
        ans+=" "+s.substr(arr[arr.size()-1]);
        return ans;
    }
};