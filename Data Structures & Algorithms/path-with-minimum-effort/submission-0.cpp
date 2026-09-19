class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        dist[0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0}); // difference , row , col 
        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};
        while(!pq.empty()){
            auto curr = pq.top();
            int diff = curr[0];
            int row = curr[1];
            int col = curr[2];
            pq.pop();
            if(row == rows-1 && col == cols-1)
                return diff;
            if(diff > dist[row][col]) 
                continue;
            for(int i=0; i<4; i++){
                int nr = row+dr[i];
                int nc = col+dc[i];
                if(nr<0 || nc<0 || nr>=rows || nc>=cols)
                    continue;
                int step = max(diff, abs(heights[row][col] - heights[nr][nc]));
                if(step < dist[nr][nc]){
                    dist[nr][nc] = step;
                    pq.push({step, nr, nc});
                }
            }
        } 
        return 0;
    }
};