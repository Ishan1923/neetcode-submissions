class Solution {
public:

    int f(int r, int c, const vector<vector<int>>& mat, vector<vector<int>>& memo){
        int m = mat.size(), n = mat[0].size();
        if(r < 0 || r >= m || c < 0 || c >= n) return 0;

        if(memo[r][c] != -1) return memo[r][c];

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, -1, 0, 1};

        int len = 0;

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            if(mat[nr][nc] <= mat[r][c]) continue;
            len = max(len, f(nr, nc, mat, memo) + 1);
        }

        return memo[r][c] = len;

    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> memo(m, vector<int>(n, -1));

        int mxLen = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mxLen = max(mxLen, f(i, j, matrix, memo) + 1);
            }
        }


        return mxLen;

    }
};
