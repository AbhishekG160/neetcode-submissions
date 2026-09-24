class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<bool>> boxs(9, vector<bool>(9, false));

        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++){
                if(board[i][j] == '.')
                    continue;
                int val = board[i][j]-'1';
                int box = (i/3)*3+(j/3);
                if(rows[i][val] || cols[j][val] || boxs[box][val])
                    return false;
                rows[i][val] = true;
                cols[j][val] = true;
                boxs[box][val] = true;
            }
        return true;
    }
};
