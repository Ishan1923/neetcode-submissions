class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int n = board.size(), m = board[0].size();

        vector<unordered_map<int, int>> cols(9);
        vector<unordered_map<int, int>> rows(9);
        vector<unordered_map<int, int>> boxes(9);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == '.') continue;

                int bx_idx = (i / 3) * 3 + (j / 3);

                if(rows[i].count(board[i][j]) ||
                   cols[j].count(board[i][j]) ||
                   boxes[bx_idx].count(board[i][j])) return false;

                rows[i][board[i][j]]++;
                cols[j][board[i][j]]++;
                boxes[bx_idx][board[i][j]]++;
            }
        }

        return true;
    }
};
