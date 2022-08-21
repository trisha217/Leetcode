class Solution {
    public int[] movesToStamp(String stamp, String target) {
        List<Integer> list=new ArrayList<Integer>();  
        char[] t= target.toCharArray();
        char[] s= stamp.toCharArray();
        int count = 0;
        boolean[] vis =new boolean[t.length];
        while(count!=t.length){
            boolean didChange = false;
            for(int i=0;i<=t.length-s.length;i++){
                if(!vis[i] && canReplace(t,i,s)){
                    count = replace(t,i,s.length,count);
                    vis[i]= true;
                    didChange = true;
                    list.add(i);
                    if(count == t.length){
                        break;
                    }
                }
            }
            if(!didChange){
                return new int[0];
            }
        }
        int[] ans = new int[list.size()];
        int j=0;
        for(int i=list.size()-1;i>=0;i--){
            ans[j++]=list.get(i);
        }
        return ans;
    }
    boolean canReplace(char[] tchar,int pos, char[] schar){
        for(int i=0;i<schar.length;i++){
            if(tchar[i+pos] != '?' && tchar[i+pos] != schar[i]){
                return false;
            }
        }
        return true;
    }
    
    int replace(char[] tchar, int pos, int len, int count){
        for(int i=0;i<len;i++){
            if(tchar[i+pos] != '?'){
                tchar[i+pos]= '?';
                count++;
            }
        }
        return count;
    }
}