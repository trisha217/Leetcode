class TimeMap {
    private Map<String,List<Data>> map;
    public TimeMap() {
        map = new HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {
        if(!map.containsKey(key)){
            map.put(key,new ArrayList<>());
        }
        map.get(key).add(new Data(value,timestamp));
    }
    
    public String get(String key, int timestamp) {
        if(!map.containsKey(key)){
            return "";
        }
        List<Data> data = map.get(key);
        return solve(data,timestamp);
    }
    private String solve(List<Data> data, int target){
        int left = 0;
        int right = data.size()-1;
        while(left<right){
            int mid = (left+right+1)/2;
            if(data.get(mid).timeStamp<=target){
                left = mid;
            }
            else{
                right = mid-1;
            }
        }
        Data obj = data.get(left);
        return obj.timeStamp>target ? "" : obj.val;
    }
    
    class Data{
        String val;
        int timeStamp;
        public Data(String val, int timeStamp){
            this.val=val;
            this.timeStamp=timeStamp;
        }
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */