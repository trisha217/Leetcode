class Solution {
public:
    int compareVersion(string version1, string version2) {
        int a=0,b=0;
        int i=0,j=0;
        while(i<version1.size()|| j< version2.size()){
            a=0,b=0;
            while(i<version1.size() && version1[i]!='.' ){
                int temp = version1[i]-'0';
                a = a* 10 + temp;
                i++;
            }
            i++;
            while(j<version2.size() && version2[j]!='.'){
                int temp = version2[j]-'0';
                b = b* 10 + temp;
                j++;
            }
            j++;
            if(a>b) return 1;
            else if(b>a) return -1;
        }
        return 0;
    }
};