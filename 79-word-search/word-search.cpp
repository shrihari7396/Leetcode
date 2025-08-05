class Solution {
private:
    int x[4] = {-1, 0, 1, 0};
    int y[4] = {0, -1, 0, 1};
    bool f(int i, int j, int m, int n, vector<vector<bool>>& vis, vector<vector<char>>& board, string& word, int idx) {
        if(word.size() == idx) return true;
        if(i < 0 || j < 0 || i >= m || j >= n || vis[i][j] || word[idx] != board[i][j]) return false;
        vis[i][j] = true;
        for(int k = 0; k < 4; k++) {
            int xnew = x[k] + i;
            int ynew = y[k] + j;
            if(f(xnew, ynew, m, n, vis, board, word, idx + 1)) return true;
        }
        vis[i][j] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] && f(i, j, m, n, vis, board, word, 0)) return true;
            }
        }
        return false;
    }
};