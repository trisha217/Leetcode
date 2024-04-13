class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxi =0;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i])){
                int h = heights[st.top()];
                st.pop();
                int w;
                if(st.empty())
                    w = i;
                else
                    w = i - st.top() - 1;
                maxi = max(maxi,h*w);
            }
            st.push(i);
        }  
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxi = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> mat(row,vector<int> (col,0));
        vector<int> height(col,0);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                mat[i][j] = matrix[i][j] - '0'; // Convert char to int
                if (mat[i][j] == 1) 
                    height[j]++;
                else 
                    height[j] = 0;
            }
            int area = largestRectangleArea(height);
            maxi = max(maxi, area);
        }
        return maxi;
    }
    //intMatrix[i][j] = matrix[i][j] - '0';
    // int maxArea = 0;
    // vector<int> height(m, 0);
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         if (mat[i][j] == 1) height[j]++;
    //         else height[j] = 0;
    //     }
    //     int area = largestRectangleArea(height);
    //     maxArea = max(maxArea, area);
    // }
    // return maxArea;
};