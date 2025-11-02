class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (auto& g : guards)
            grid[g[0]][g[1]] = 1; // guard
        for (auto& w : walls)
            grid[w[0]][w[1]] = 2; // wall

        vector<vector<bool>> guarded(m, vector<bool>(n, false));

        // left → right sweep
        for (int i = 0; i < m; i++) {
            bool seen = false;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    seen = true;
                else if (grid[i][j] == 2)
                    seen = false;
                else if (seen)
                    guarded[i][j] = true;
            }
        }

        // right → left
        for (int i = 0; i < m; i++) {
            bool seen = false;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1)
                    seen = true;
                else if (grid[i][j] == 2)
                    seen = false;
                else if (seen)
                    guarded[i][j] = true;
            }
        }

        // top → bottom
        for (int j = 0; j < n; j++) {
            bool seen = false;
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 1)
                    seen = true;
                else if (grid[i][j] == 2)
                    seen = false;
                else if (seen)
                    guarded[i][j] = true;
            }
        }

        // bottom → top
        for (int j = 0; j < n; j++) {
            bool seen = false;
            for (int i = m - 1; i >= 0; i--) {
                if (grid[i][j] == 1)
                    seen = true;
                else if (grid[i][j] == 2)
                    seen = false;
                else if (seen)
                    guarded[i][j] = true;
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0 && !guarded[i][j])
                    count++;

        return count;
    }
};