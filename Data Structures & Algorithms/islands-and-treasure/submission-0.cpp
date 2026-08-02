class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;

        int m = grid.size();
        int n = grid[0].size();

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }


        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if(grid[nr][nc] == INT_MAX){
                    grid[nr][nc] = grid[r][c] + 1; 
                    q.push({nr, nc});
                }
            }
        }
    }
};
