class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int i = 0, j = 0, n = grid.size();

        for(j = 1; j < n; j++) {
            int tmpI = i;
            int tmpJ = j;
            vector<int> vec;
            while(tmpI < n && tmpJ < n) {
                vec.emplace_back(grid[tmpI++][tmpJ++]);
            }
            sort(vec.begin(), vec.end());

            tmpI = i;
            tmpJ = j;
            int ind = 0;
            while(tmpI < n && tmpJ < n) {
                grid[tmpI++][tmpJ++] = vec[ind++];
            }
        }
        j = 0;
        for(i = 0; i < n; i++) {
            int tmpI = i;
            int tmpJ = j;
            vector<int> vec;
            while(tmpI < n && tmpJ < n) {
                vec.emplace_back(grid[tmpI++][tmpJ++]);
            }
            sort(vec.rbegin(), vec.rend());

            tmpI = i;
            tmpJ = j;
            int ind = 0;
            while(tmpI < n && tmpJ < n) {
                grid[tmpI++][tmpJ++] = vec[ind++];
            }
        }
        return grid;
    }
};