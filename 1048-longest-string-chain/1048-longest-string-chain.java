class Solution {
    public int longestStrChain(String[] words) {
        Arrays.sort(words,(a,b) ->a.length()-b.length());
        int res = 0;
        Map<String,Integer> memo = new HashMap<>();
        for(int i=0;i<words.length;i++){
            memo.put(words[i],1);
            for(int j=0;j<words[i].length();j++){
                StringBuilder cur = new StringBuilder(words[i]);
                String next = cur.deleteCharAt(j).toString();
                if(memo.containsKey(next)){
                    memo.put(words[i],Math.max(memo.get(words[i]),memo.get(next)+1));
                }
            }
            res = Math.max(memo.get(words[i]),res);
        }
        return res;
    }
}