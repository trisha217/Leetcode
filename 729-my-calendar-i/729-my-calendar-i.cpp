class MyCalendar {
    unordered_map<int,int> bookings;
public:
    bool book(int start1, int end1) {
        for(auto& [start2,end2] : bookings){
            if(!(start1>=end2 || start2>=end1)){
                return false;
            }
        }
        bookings[start1]=end1;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
