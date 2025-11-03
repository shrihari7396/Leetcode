
class Solution {
private:
    int dfs(int i, int j, int n, int m, string& s, string& t, vector<vector<int>>& dp) {
        if(j == m) {
            return 1;
        } else if(i == n) {
            return 0;
        } else if(dp[i][j] != -1) return dp[i][j];

        int ways = dfs(i+1, j, n, m, s, t, dp);
        if(s[i] == t[j]) {
            ways += dfs(i+1, j+1, n, m, s, t, dp);
        }
        return dp[i][j] = ways;
    }
public:
    int numDistinct(string s, string t) {
        int m = t.size();    
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return dfs(0,0,n,m,s,t,dp);
    }
};