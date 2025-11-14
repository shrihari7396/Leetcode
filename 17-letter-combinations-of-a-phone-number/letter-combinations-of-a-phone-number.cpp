class Solution {
private:
    void dfs(int i, string s, int n, unordered_set<string>& ans, string curr, unordered_map<char, vector<char>>& m) {
        if(i == n) {
            ans.insert(curr);
            return;
        }

        vector<char> temp = m[s[i]];
        for(auto& it : temp) {
            dfs(i+1, s, n, ans, curr + it, m);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> m;
        unordered_set<string> ans;
        m['2'] = {'a', 'b', 'c'};
        m['3'] = {'d', 'e', 'f'};
        m['4'] = {'g', 'h', 'i'};
        m['5'] = {'j', 'k', 'l'};
        m['6'] = {'m', 'n', 'o'};
        m['7'] = {'p', 'q', 'r', 's'};
        m['8'] = {'t', 'u', 'v'};
        m['9'] = {'w', 'x', 'y', 'z'};
        int n = digits.size();
        dfs(0, digits, n, ans, "", m);
        return vector<string>(ans.begin(), ans.end());
    }
};