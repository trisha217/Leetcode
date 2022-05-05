class Solution {
    public boolean buddyStrings(String a, String b) {
         if (a.length() != b.length()) 
             return false;
        
        if(a.equals(b)){
            HashSet<Character> unique = new HashSet();
            for(char c:a.toCharArray()){
                unique.add(c);
            }
            if(unique.size()<a.length()){
                return true;
            }
            else{
                return false;
            }
        }
        
        List<Integer> diff= new ArrayList();
        for(int i=0;i<a.length();i++){
            if(a.charAt(i)!=b.charAt(i)){
                diff.add(i);
            }
        }
        if(diff.size()==2 && (a.charAt(diff.get(0))==b.charAt(diff.get(1))) && (b.charAt(diff.get(0))==a.charAt(diff.get(1))) ){
            return true;
        }
        else{
            return false;
        }
    }
}