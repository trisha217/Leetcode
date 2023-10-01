public class Solution {
    public String reverseWords(String s) {
        char[] ch = s.toCharArray();
        for(int i=0;i<ch.length;i++){
            //if the character is not a space
            if(ch[i]!=' '){
                int j = i;
                //move j to the end of the word till you encounter a space
                while(j + 1<ch.length && ch[j+1]!=' '){
                    j++;
                }
                rev(ch,i,j);
                i = j;
            }
        }
        return new String(ch);
    }
    private void rev(char[] ca, int i, int j) {
        for (; i < j; i++, j--) {
            char tmp = ca[i];
            ca[i] = ca[j];
            ca[j] = tmp;
        }
    }
}
  