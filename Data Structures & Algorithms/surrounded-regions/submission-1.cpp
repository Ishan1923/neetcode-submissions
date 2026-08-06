class Solution {
public:

    void dfs(int r, int c, int m, int n, vector<vector<char>>& board){

        if(r >= m || c >= n || r < 0 || c < 0) return;

        if(board[r][c] != 'O') return;

        board[r][c] = '#';


        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};


        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            dfs(nr, nc, m, n, board);
        }


    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            dfs(i, n - 1, m, n, board);
            dfs(i, 0, m, n, board);
        }

        for(int i = 0; i < n; i++){
            dfs(0, i, m, n, board);
            dfs(m - 1, i, m, n, board);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
