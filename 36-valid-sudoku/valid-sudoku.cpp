class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        vector<unordered_set<int>> rows(10);
        vector<unordered_set<int>> cols(10);
        
        for(int i = 0 ; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(b[i][j] != '.') {
                    int num = (b[i][j]-'0');
                    if(rows[i].find(num) != rows[i].end()) return false;
                    if(cols[j].find(num) != cols[j].end()) return false;
                    cols[j].insert(num);
                    rows[i].insert(num);
                }
            }
        }

        for(int i = 0; i < 9; i+=3) {
            for(int j = 0; j < 9; j+=3) {        
                unordered_set<int> hash;
                for(int row = i; row < i+3 && row < 9; row++) {
                    for(int col = j; col < j + 3 && col < 9; col++) {
                        if(b[row][col] != '.') {
                            int num = (b[row][col]-'0');
                            if(hash.find(num) != hash.end()) return false;
                            hash.insert(num);
                        }
                    }
                }
            }
        }
        return true;
    }
};