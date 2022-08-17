class Solution {
    public int uniqueMorseRepresentations(String[] words){
        String[] alpha= {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        Set<String> codes = new HashSet<>();
        for (String word : words) {
            StringBuilder beta = new StringBuilder();
            for (int i = 0, n = word.length(); i < n; i++) {
                beta.append(alpha[word.charAt(i) - 'a']);
            }
            codes.add(beta.toString());
        }

        return codes.size();
        
    }
}