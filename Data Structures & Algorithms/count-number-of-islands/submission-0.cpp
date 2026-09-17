class Solution {
public:
    int n,m;
    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& vis){
        vis[r][c] = true;
        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {1, -1, 0, 0};
        for(int i=0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc] == '1' && vis[nr][nc] == false)
                dfs(nr, nc, grid, vis);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == '1' && visited[i][j] == false){
                    dfs(i,j, grid, visited);
                    count++;
                }
        return count;
    }
};
