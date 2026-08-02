class Solution {
public:

    using ll = long long;

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int mx = 0;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0 || vis[i][j] == 1) continue;

                queue<pair<int, int>> q;
 
                q.push({i, j});
                vis[i][j] = 1;

                int ar = 0;

                while(!q.empty()){
                    auto [r, c] = q.front();
                    q.pop();

                    ar++;

                    for(int k = 0; k < 4; k++){
                        int nr = r + dr[k];
                        int nc = c + dc[k];

                        if(nr < 0|| nr >= m || nc < 0 || nc >= n) continue;
                        if(grid[nr][nc] == 0 || vis[nr][nc] == 1) continue;

                        q.push({nr, nc});
                        vis[nr][nc] = 1;
                    }

                }

                mx = max(mx, ar);

            }
        }

        return mx;

    }
};
