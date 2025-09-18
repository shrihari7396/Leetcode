class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        unordered_map<int, pair<int,int>> squareMap; // map square → (row,col)
        bool leftToRight = true;
        int counter = 1;

        for(int i = n - 1; i >= 0; i--) {  // bottom to top
            if(leftToRight) {
                for(int j = 0; j < n; j++) {
                    squareMap[counter++] = {i, j};
                }
            } else {
                for(int j = n - 1; j >= 0; j--) {
                    squareMap[counter++] = {i, j};
                }
            }
            leftToRight = !leftToRight; // toggle direction
        }

        // BFS setup
        vector<int> visited(n*n + 1, 0);
        queue<pair<int,int>> q; // {square, moves}
        q.push({1,0});
        visited[1] = 1;

        while(!q.empty()) {
            auto [s, moves] = q.front(); q.pop();
            if(s == n*n) return moves;

            for(int i = 1; i <= 6; i++) {
                int next = s + i;
                if(next > n*n) break;

                auto [r,c] = squareMap[next];
                if(board[r][c] != -1) next = board[r][c]; // ladder/snake

                if(!visited[next]) {
                    visited[next] = 1;
                    q.push({next, moves+1});
                }
            }
        }

        return -1;
    }
};
