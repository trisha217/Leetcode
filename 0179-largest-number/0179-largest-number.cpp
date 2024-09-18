class Solution {
public:
 static bool comparator(int a,int b){
    string s1=to_string(a);
    string s2=to_string(b);
    if(s1+s2>s2+s1){
        return true;
    }
    return false;
    // return s1+s2>s2+s1;
 }
    string largestNumber(vector<int>& nums) {
        map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            string s=to_string(num);
            int digit=s[0]-'0';
            mp[digit].push_back(num);
        
        }
        string ans="";
        for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
            auto v=it->second;
            sort(v.begin(),v.end(),comparator);
            for(int i=0;i<v.size();i++){
               ans+=to_string(v[i]);
            }
        }
        if(ans[0]=='0') return "0";
        return ans;

    }
};