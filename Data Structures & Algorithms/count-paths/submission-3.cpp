class Solution {
public:

    int f(int r, int c, vector<vector<int>>& memo){
        if(r == 0 && c == 0) return 1; // base case
        if(r < 0 || c < 0) return 0; // edge case

        if(memo[r][c] != -1) return memo[r][c];

        int top = f(r - 1, c, memo);

        int left = f(r, c - 1, memo);

        return memo[r][c] = top + left;

    }

    int uniquePaths(int m, int n) {
        // vector<vector<int>> memo(m, vector<int>(n, -1));
        // return f(m - 1, n - 1, memo);


        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = 1;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(i == 0 && j == 0) continue;

                int top = (i == 0) ? 0 : dp[i - 1][j];

                int left = (j == 0) ? 0 : dp[i][j - 1];

                dp[i][j] = top + left;
            }
        }

        return dp[m - 1][n - 1];

    }
};
