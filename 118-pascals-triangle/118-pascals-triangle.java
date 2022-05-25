class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans= new ArrayList<List<Integer>>();
        List<Integer> prev=null;
        for(int i=0;i<numRows;i++){
            List<Integer> res=new ArrayList<>();
            
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){//first and last elements are 1
                    res.add(1);
                }else{
                res.add(prev.get(j)+prev.get(j-1));//rest elements are just on prev row on j & j-1
                }
                
            }
            prev=res;
            ans.add(res);
        }
        return ans;
    }
}