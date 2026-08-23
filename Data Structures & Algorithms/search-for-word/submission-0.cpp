class Solution {
public:

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};
    
    
    bool dfs(int r, int c, int idx, const vector<vector<char>>& mat, vector<vector<bool>>& vis, const string& word){
        
        int n = mat.size(), m = mat[0].size();
        
        if(mat[r][c] != word[idx]) return false;
        
        if(idx == word.size() - 1) return true; // base case && MAKE SURE THIS IS EXCUTED AFTER THE LAST ELEMENT IS CHECKED!!
        
        bool ans = false;
        
        for(int i = 0; i < 4; i++){
            
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if(nr >= n || nr < 0 || nc >= m || nc < 0) continue;
            if(vis[nr][nc] == true) continue;

            
            vis[nr][nc] = true;
            if(dfs(nr, nc, idx + 1, mat, vis, word)){
                ans = true;
                vis[nr][nc] = false;
                break;
            }
            vis[nr][nc] = false;
            
            if(ans) break;
        }
        
        return ans;
    }
  
  
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        // Code here
        
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == word[0]){
                    vis[i][j] = true;
                    if(dfs(i, j, 0, mat, vis, word)) return true;
                    vis[i][j] = false;
                    
                }
            }
        }
        
        return false;
        
    }

    bool exist(vector<vector<char>>& board, string word) {
        return isWordExist(board, word);
    }
};
