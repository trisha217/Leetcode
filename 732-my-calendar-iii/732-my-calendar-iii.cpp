class MyCalendarThree {
private:
	map<int, int> mp;
public:
	MyCalendarThree() {
			mp;
	} 
	int book(int start, int end) {
		mp[start]++;
		mp[end]--;
		int maxBooking = 0, sum = 0;
		for(auto &x : mp) {
			sum += x.second;
			maxBooking = max(maxBooking, sum);
		}
		return maxBooking;
	}
};
