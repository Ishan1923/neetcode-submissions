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
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return f(m - 1, n - 1, memo);
    }
};
