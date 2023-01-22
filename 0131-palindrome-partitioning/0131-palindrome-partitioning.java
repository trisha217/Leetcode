class Solution {
    List<List<String>>l=new ArrayList();
    public List<List<String>> partition(String s) {
        backtrack(new ArrayList<>(),0,s);
        return l;
    }
    public void backtrack(ArrayList<String>row,int i,String s){
        if(i==s.length()){
            l.add(new ArrayList<>(row));
            return;
        }
        for(int j=i;j<s.length();j++){
            if(isPalindrome(s,i,j)){
                row.add(s.substring(i,j+1));
                backtrack(row,j+1,s);
                row.remove(row.size()-1);
            }
        }
    }
    public boolean isPalindrome(String s,int i,int j){
        while(i<=j){
            if(s.charAt(i++)!=s.charAt(j--)){
                return false;
            }
        }
        return true;
    }
}