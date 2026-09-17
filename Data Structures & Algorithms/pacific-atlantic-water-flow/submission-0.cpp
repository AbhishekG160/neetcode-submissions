class Solution {
public:
    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, queue<pair<int, int>>& q,int m, int n){
        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {1, -1, 0, 0};
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nc>=0 && nr<m && nc<n && !visited[nr][nc] && heights[nr][nc] >= heights[r][c]){
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // water from high to low 
        // start from boundary to inward -> low to high
        // reachable from atlantic and reachable from pacific --> intersection --> solution nodes
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        queue<pair<int, int>> atl;
        queue<pair<int, int>> pac;

        //insert border elems
        for(int i=0; i<m; i++){
            atl.push({i, n-1});
            atlantic[i][n-1] = true;
            pac.push({i, 0});
            pacific[i][0] = true;
        }
        for(int j=0; j<n; j++){
            atl.push({m-1, j});
            atlantic[m-1][j] = true;
            pac.push({0, j});
            pacific[0][j] = true;
        }
        bfs(heights, atlantic, atl, m, n);
        bfs(heights, pacific, pac, m, n);
        
        vector<vector<int>> result;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(atlantic[i][j] && pacific[i][j])
                    result.push_back({i, j});
            }
        return result;
    }
};
