class Solution {
public:

    void dfs(int r, int c, int m, int n, int prev, const vector<vector<int>>& heights, vector<vector<bool>>& ocean){
        if(r < 0 || c < 0 || r >= m || c >= n) return;

        if(ocean[r][c]) return;

        if(prev > heights[r][c]) return;

        ocean[r][c] = true;


        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            dfs(nr, nc, m, n, heights[r][c], heights, ocean);
        }


    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        vector<vector<int>> ans;

        for(int i = 0; i < m; i++){
            dfs(i, n - 1, m, n, INT_MIN, heights, atlantic);
        }
        for(int i = 0; i < m; i++){
            dfs(i, 0, m, n, INT_MIN, heights, pacific);
        }
        for(int i = 0; i < n; i++){
            dfs(m - 1, i, m, n, INT_MIN, heights, atlantic);
        }
        for(int i = 0; i < n; i++){
            dfs(0, i, m, n, INT_MIN, heights, pacific);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(atlantic[i][j] && pacific[i][j]) ans.push_back({i, j});
            }
        }

        return ans;

    }
};
