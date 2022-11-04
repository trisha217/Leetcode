class Solution {
    private boolean f(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
                || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    public String reverseVowels(String s) {
        char[] str = s.toCharArray();
        int n = s.length();
        int i=0;
        int j=n-1;
        while(i<j){
            while(i<j && !f(str[i])){
                i++;
            }
            while(i<j && !f(str[j])){
                j--;
            }
            if(i<j){
                char temp = str[i];
                str[i++] = str[j];
                str[j--] = temp;
            }
        } 
        return new String(str);
    }
}