class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int numOfIslands = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '0' || vis[i][j] == 1) continue;

                queue<pair<int, int>> q;

                q.push({i, j});
                vis[i][j] = 1;

                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};

                while(!q.empty()){
                    auto [r, c] = q.front();
                    q.pop();

                    for(int i = 0; i < 4; i++){
                        int nr = r + dr[i];
                        int nc = c + dc[i];
                        if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                        if(grid[nr][nc] == '0' || vis[nr][nc]) continue;
                        q.push({nr, nc});
                        vis[nr][nc] = 1;
                    }
                }

                numOfIslands++;

            }
        }
        return numOfIslands;
    }
};
