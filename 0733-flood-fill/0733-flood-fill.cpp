class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor != color) {
            dfs(image, sr, sc, color, originalColor);
        }
        return image;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int org){
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size() || image[sr][sc]!=org){
            return;
        }
        image[sr][sc] = color;
        dfs(image,sr-1,sc,color,org);
        dfs(image,sr+1,sc,color,org);
        dfs(image,sr,sc-1,color,org);
        dfs(image,sr,sc+1,color,org);
    }
};