class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;

        int fresh = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1)
                    fresh++;
                if(grid[i][j] == 2)
                    q.push({i,j});
            }
        
        int timer = 0;
        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};
        while(!q.empty() && fresh>0){
            int s = q.size();
            timer++;
            for(int step = 0; step<s; step++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i=0; i<4; i++){
                    int nr = r+dr[i];
                    int nc = c+dc[i];
                    if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return (fresh == 0)?timer:-1;
    }
};
