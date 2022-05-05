class Solution {
    public boolean isPalindrome(int x) {
        String a=Integer.toString(x);
        String b ="";
        char ch;
        for (int i=0; i<a.length(); i++)
        {
            ch= a.charAt(i); //extracts each character
            b= ch+b; //adds each character in front of the existing string
        }
        if(a.equals(b)){
            return true;
        }
        return false;
    }
}