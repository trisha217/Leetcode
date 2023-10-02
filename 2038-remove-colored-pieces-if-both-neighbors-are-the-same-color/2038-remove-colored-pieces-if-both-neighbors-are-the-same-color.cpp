class Solution {
public:
    bool winnerOfGame(string colors) 
    {
        int n = colors.size();
    
        int acount=0,bcount=0;
        
        for(int i=1;i<n;i++)
        {
            if(colors[i]=='A')
            acount+= (colors[i-1]=='A' && colors[i+1]=='A');
            else
            bcount+= (colors[i-1]=='B' && colors[i+1]=='B');
        }
        
       return (acount>=++bcount);
    }
};