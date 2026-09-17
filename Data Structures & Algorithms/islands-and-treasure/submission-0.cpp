class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // multi point bfs. similar to rotten oranges
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == 0)
                    q.push({i,j});
        
        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc] > 1e6){
                    grid[nr][nc] = 1+grid[r][c];
                    q.push({nr, nc});
                }
            }
        }
    }
};
