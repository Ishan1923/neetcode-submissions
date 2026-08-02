class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        queue<pair<int, pair<int, int>>> q;

        int rotten = 0;
        int empty = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({0, {i, j}});
                    rotten++;
                }
                else if(grid[i][j] == 0){
                    empty++;
                }
            }
        }

        if(empty == m*n) return 0;

        int minutes = -1;

        while(!q.empty()){
            auto [t, it] = q.front();
            auto [r, c] = it;
            q.pop();

            minutes = t;

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                if(grid[nr][nc] == 1){
                    rotten++;
                    grid[nr][nc] = 2;
                    q.push({t + 1, {nr, nc}});
                }
            }
        }

        if(rotten == m*n - empty) return minutes;
        return -1;

    }
};
