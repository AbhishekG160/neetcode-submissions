class Solution {
public:  
    int n,m;
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis){
        vis[r][c] = true;
        int curr_area = 1;
        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {1, -1, 0, 0};
        for(int i=0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc] == 1 && vis[nr][nc] == false)
                curr_area += dfs(nr, nc, grid, vis);
        }
        return curr_area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int result = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == 1 && visited[i][j] == false){
                    int area = dfs(i,j, grid, visited);
                    result = max(area, result);
                }
        return result;
    }
};
