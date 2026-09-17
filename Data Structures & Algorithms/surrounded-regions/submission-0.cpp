class Solution {
    int m,n;
public:
    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<bool>>& visited){
        visited[r][c] = true;
        board[r][c] = 'R';
        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};
        for(int i=0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nc>=0 && nr<m && nc<n && board[nr][nc] == 'O' && !visited[nr][nc])
                dfs(nr, nc, board, visited);
        }
    }
    void solve(vector<vector<char>>& board) {
        m = board.size(); 
        n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            if(board[i][0] == 'O')
                dfs(i, 0, board, visited);
            if(board[i][n-1] == 'O')
                dfs(i, n-1, board, visited);
        }
        for(int j=0; j<n; j++){
            if(board[0][j] == 'O')
                dfs(0, j, board, visited);
            if(board[m-1][j] == 'O')
                dfs(m-1, j, board, visited);
        }
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == 'R')
                    board[i][j] = 'O';
            }
    }
};
