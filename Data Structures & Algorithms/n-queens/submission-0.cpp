class Solution {
public:

    void solve(int r, vector<string>& board, vector<vector<string>>& answers, const int& n, int left, vector<int>& cols, vector<int>& diagonals1, vector<int>& diagonals2){

        if(left == 0){
           answers.push_back(board);
           return; 
        }
        if(r >= n) return;



        for(int c = 0; c < n; c++){
            if(cols[c] > 0 || diagonals1[r + c] > 0 || diagonals2[n - r + c] > 0) {
                continue;
            }
                
            
            cols[c]++;
            diagonals1[r + c]++;
            diagonals2[n - r + c]++;
            board[r][c] = 'Q';

            solve(r + 1, board, answers, n, left - 1, cols, diagonals1, diagonals2);

            board[r][c] = '.';
            cols[c]--;
            diagonals1[r + c]--;
            diagonals2[n - r + c]--;
        }


    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> answers;

        vector<int> cols(n + 1, 0);
        vector<int> diagonals1(n + n + 1, 0);
        vector<int> diagonals2(n + n + 1, 0);

        solve(0, board, answers, n, n, cols, diagonals1, diagonals2);

        return answers;
    }
};
