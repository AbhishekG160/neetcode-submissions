class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // max_height till now , row , col
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        pq.push({grid[0][0] , 0, 0});

        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};

        while(!pq.empty()){
            int curr_h = pq.top()[0];
            int r = pq.top()[1];
            int c = pq.top()[2];
            pq.pop();
            if(r == n-1 && c == n-1)    
                return curr_h;
            if(visited[r][c])
                continue; // already walked from this
            visited[r][c] = true;

            for(int i=0; i<4; i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<n && !visited[nr][nc]){
                    int next_h = max(grid[nr][nc] , curr_h);
                    pq.push({next_h , nr, nc});
                }
            }
        }

        return -1;
    }
};
