class Solution {
    public String reversePrefix(String word, char ch) {
        String str="";
        int n =word.length();
        int index = word.indexOf(ch);
        if(index<n){
            String sub = word.substring(0,index+1); 
            StringBuilder reversedSub = new StringBuilder(sub).reverse();
            String end = word.substring(index+1,n);
            return reversedSub+end;
        } 
        //System.out.println(index);
        return word;
    }
}