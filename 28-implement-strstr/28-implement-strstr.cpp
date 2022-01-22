class Solution {
public:
    int strStr(string haystack, string needle) {
        int x = needle.length();
        int y = haystack.length();
        int flag = 0;
        int index = -1;
        if( x == 0){
            return 0;
        }
        if(x>y){
            return -1;
        }
        for(int i=0;i<y;i++)
        {
            if(haystack[i] == needle[0] )
            {
                if(haystack.compare(i,needle.size(),needle)==0) 
                    return i;
            }   
        } 
        return index;
    }
};