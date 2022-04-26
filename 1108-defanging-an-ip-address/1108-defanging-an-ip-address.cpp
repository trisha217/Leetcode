class Solution 
{
public:
    string defangIPaddr(string address) 
    {
        int len = address.size();
        string neww;
        int j =0;
        for(int i=0;i<len;i++)
        {
            if(address[i]=='.'){
                neww+='[';
                neww+='.';
                neww+=']';
            }
            else{
                neww+=address[i];
            }
        }  
        return neww;
    }
};