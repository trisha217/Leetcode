class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int, pair<int, int>> idx{{0,{1,-1}}};
        int current = 0;
        int answer = 0;
        for (int i = 0; i < arr.size(); i++) {
            current ^= arr[i];
            auto& [cnt, sum] = idx[current];
            answer += cnt*(i-1)-sum;
            sum += i;
            cnt++;
        }
        return answer;
    }
};