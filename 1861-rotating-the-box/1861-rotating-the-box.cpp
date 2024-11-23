class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        stack<pair<int, int>>stones;
        vector<vector<char>>ans(m, vector<char>(n, '.'));
        for(int i = 0; i < n; i++){
            int s = 0;
            for(int j = 0; j < m; j++){
                s += (box[i][j] == '#');
                if(box[i][j] == '*'){
                    stones.push({j,s});
                    s = 0;
                }
            }
            for(int x = m-1; x >= 0; x--){
                if(s>0){
                    ans[x][n-i-1] = '#';
                    s--;
                    continue;
                }
                if(stones.empty()){
                    ans[x][n-i-1] = box[i][x] == '*'?'*': '.';
                    continue;
                }

                if(x == stones.top().first){
                    s = stones.top().second;
                    stones.pop();
                    ans[x][n-i-1] = '*';
                }
            }
            stones = stack<pair<int,int>>();
        }
        return ans;
    }
};