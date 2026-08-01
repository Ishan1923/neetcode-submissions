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
                rows[i][board[i][j]]++;
                cols[j][board[i][j]]++;
                boxes[(i / 3) * 3 + (j / 3)][board[i][j]]++;
            }
        }

        for(const auto& map : cols){
            for(const auto& [num, freq] : map)
                if(freq > 1) return false;
        }

        for(const auto& map : rows){
            for(const auto& [num, freq] : map)
                if(freq > 1) return false;
        }

        for(const auto& map : boxes){
            for(const auto& [num, freq] : map)
                if(freq > 1) return false;
        }

        return true;
    }
};
