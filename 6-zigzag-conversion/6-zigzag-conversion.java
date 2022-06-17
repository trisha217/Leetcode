class Solution {
    public String convert(String s, int nRows) {
    int len = s.length();
    if(len<=nRows||nRows<=1) return s; //such condition can't form the zigzag route.
    
    StringBuilder[] result = new StringBuilder[nRows]; //string buffer array to hold each row's result
    
    //initialize the string buffer
    for(int i = 0; i < result.length; i++){
        result[i] = new StringBuilder();
    }
    
    //divide the groups into chunks with size (nRows*2-2).
    int chunk = nRows*2-2; //3->4, 4->6, 5->7, etc.
    
    for(int i = 0; i < len; i++){
        int group = i%chunk; //get the index of the element in the chunk
        
        //if they are less then nRows, this element is vertically aligned from top to buttom
        if(group<nRows){
            result[group].append(s.charAt(i));
        }
        //otherwise, it falls onto the slope in reversed direction
        else{
            result[chunk-group].append(s.charAt(i));
        }
    }
    
    //combine the groups into final array.
    StringBuilder sb = new StringBuilder();
    for(int i = 0; i < nRows; i++){
        sb.append(result[i].toString());
    }
    return sb.toString();
}
}