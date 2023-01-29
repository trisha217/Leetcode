class LFUCache {
public:
    set<vector<int>> st;
    unordered_map<int,vector<int>> mp;
    int time = 0;
    int cap;
    LFUCache(int capacity) {
       cap = capacity;
    }
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        int val = mp[key][0];
        int prev_freq = mp[key][1];
        int prev_time = mp[key][2];
        st.erase({prev_freq,prev_time,key,val});
        st.insert({prev_freq+1,time,key,val});
        mp[key][1]++;
        mp[key][2] = time;
        time++;
        return val;
    }
    void put(int key, int value) {
        if(!cap) return;
        if(mp.find(key)==mp.end()){
            if(cap==mp.size()){
                vector<int> vec = (*st.begin());
                st.erase(st.begin());
                mp.erase(vec[2]);
            }
            mp[key] = {value,1,time};
            st.insert({1,time,key,value});
        }
        else{
            int val = mp[key][0];
            int prev_freq = mp[key][1];
            int prev_time = mp[key][2];
            st.erase({prev_freq,prev_time,key,val});
            st.insert({prev_freq+1,time,key,value});
            mp[key][0] = value;
            mp[key][1]++;
            mp[key][2] = time;
        }
        time++;
    }
};